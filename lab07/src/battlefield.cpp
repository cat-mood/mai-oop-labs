#include "battlefield.h"

using namespace lab07;

std::mutex print_mutex;

std::unordered_map<TypeNPC, std::shared_ptr<Visitor>> visitors = {
    {BEAR, std::make_shared<VisitorBear>()},
    {KNIGHT_ERRANT, std::make_shared<VisitorKnightErrant>()},
    {ORC, std::make_shared<VisitorOrc>()}
};

std::ostream& lab07::operator<<(std::ostream& os, Battlefield& btf) {
    os << "This is a battlefield" << std::endl;
    os << "There are " << btf._npcList.size() << " fighters." << std::endl;
    for (auto npc: btf._npcList) {
        os << *npc;
    }
    return os;
}

Battlefield::Battlefield() : _size(battlefield_size, battlefield_size), _npcList(), _observers() {}

void Battlefield::attach_obs(std::shared_ptr<ObserverBattlefield> obs) {
    _observers.push_back(obs);
}

void Battlefield::detach_obs(std::shared_ptr<ObserverBattlefield> obs) {
    if (!_observers.remove(obs)) {
        throw std::logic_error("Observer not in observer list");
    }
}

void Battlefield::fill_randomly(size_t seed, size_t orcs, size_t knights, size_t bears) {
    srand(seed);
    std::shared_ptr<Factory> factoryB = std::make_shared<BearFactory>();
    std::shared_ptr<Factory> factoryO = std::make_shared<OrcFactory>();
    std::shared_ptr<Factory> factoryK = std::make_shared<KnightErrantFactory>();
    std::shared_ptr<NPC> orcNPC;
    std::shared_ptr<NPC> knightNPC;
    std::shared_ptr<NPC> bearNPC;
    size_t c_k = 0, c_b = 0, c_o = 0;
    while(c_b < bears || c_k < knights || c_o < orcs) {
        switch (rand() % 3) {
            case BEAR:
                if (c_b < bears) {
                    bearNPC = factoryB->create(rand() % (battlefield_size - 1), rand() % (battlefield_size - 1));
                    this->place_hero(bearNPC);
                    c_b++;
                }
                break;
            case KNIGHT_ERRANT:
                if (c_k < knights) {
                    knightNPC = factoryK->create(rand() % (battlefield_size - 1), rand() % (battlefield_size - 1));
                    this->place_hero(knightNPC);
                    c_k++;
                }
                break;
            case ORC:
                if (c_o < orcs) {
                    orcNPC = factoryO->create(rand() % (battlefield_size - 1), rand() % (battlefield_size - 1));
                    this->place_hero(orcNPC);
                    c_o++;
                }
                break;
            default:
                break;
        }
    }
}

void Battlefield::notify(int cmd) {
    switch (cmd) {
        case Commands::BATTLE_START:
            for (auto obs: _observers) {
                obs->battle_start(this->_size, this->_npcList);
            }
            break;
        case Commands::BATTLE_END:
            for (auto obs: _observers) {
                obs->battle_end(this->_size, this->_npcList);
            }
            break;
        default:
            throw std::logic_error("Unknown notify");
        }
}

void Battlefield::place_hero(std::shared_ptr<NPC> npc) {
    if (npc->coord().first < battlefield_size && npc->coord().first < battlefield_size) _npcList.push_back(npc);
}

void Battlefield::remove_deadmen() {
    _npcList.erase(std::remove_if(_npcList.begin(), _npcList.end(), [](std::shared_ptr<NPC> npc) {return !npc->is_alive(); }), _npcList.end());
}

void Battlefield::remove_hero(std::shared_ptr<NPC> npc) {
    if (!_npcList.remove(npc)) {
        throw std::logic_error("NPC not on battlefield");
    }
}

std::list<std::shared_ptr<NPC>> Battlefield::npc() {
    return _npcList;
}

void Battlefield::battle() {
    bool stop = false;
    std::thread fightThread(std::ref(FightManager::get()));
    this->notify(Commands::BATTLE_START);
    std::thread moveThread([this, &stop]() {
        auto start = std::chrono::system_clock::now();
        while (true) {
            if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count() > 30) {
                break;
            }
            for (auto attacker : _npcList) {
                bool success1;
                for (auto defender : _npcList) {
                    if (attacker != defender && attacker->attack_range() > defender->distance(attacker) && defender->is_alive() && attacker->is_alive()) {
                        FightManager::get().push_event({defender, attacker});
                    }
                }
            }
            for (auto npc: _npcList) {
                if (npc->is_alive()) {
                    int moveX = -npc->move_range() + std::rand() % (2 * npc->move_range());
                    int moveY = -npc->move_range() + std::rand() % (2 * npc->move_range());
                    npc->move(moveX, moveY);
                }
            }
            std::this_thread::sleep_for(50ms);
        }
        stop = true;
    });
    auto start = std::chrono::system_clock::now();
    while (true) {
        if (stop) {
            break;
        }
        const int grid{20}, step_x{battlefield_size / grid}, step_y{battlefield_size / grid}, size = (grid + 1) * (grid + 1); 
        {
            std::array<char, size> fields{0};
            for (std::shared_ptr<NPC> npc : _npcList) {
                auto [x, y] = npc->coord();
                int i = x / step_x;
                int j = y / step_y;
                if (i + grid * j > size) {
                    std::cout << i << ' ' << j << ' ' <<  i + j *grid << ' '<< size << std::endl;
                    throw std::logic_error("Problems with scale");
                }
                if (npc->is_alive())
                {
                    switch (npc->type())
                    {
                    case TypeNPC::BEAR:
                        fields[i + grid * j] = 'B';
                        break;
                    case TypeNPC::ORC:
                        fields[i + grid * j] = 'O';
                        break;
                    case TypeNPC::KNIGHT_ERRANT:
                        fields[i + grid * j] = 'S';
                        break;

                    default:
                        break;
                    }
                }
                else
                    fields[i + grid * j] = '#';
            }

            std::lock_guard<std::mutex> lck(print_mutex);
            for (int j = 0; j < grid + 1; ++j)
            {
                for (int i = 0; i < grid + 1; ++i)
                {
                    char c = fields[i + j * grid];
                    if (c != 0)
                        std::cout << "[" << c << "]";
                    else
                        std::cout << "[ ]";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            std::this_thread::sleep_for(1000ms);
        }
    };
    fightThread.join();
    moveThread.join();
    this->notify(Commands::BATTLE_END);
}

void OutputObserverBattlefield::battle_start(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& npcList) {
    std::cout << std::endl << "-------- Battle started --------" << std::endl;
    std::cout << "There are " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        std::cout << *npc;
    }
    std::cout << std::endl;
}

void OutputObserverBattlefield::battle_end(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& npcList) {
    std::cout << std::endl << "-------- Battle ended --------" << std::endl;
    std::cout << "There was " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        std::cout << *npc;
    }
    std::cout << std::endl;
}

void OutputObserverBattlefield::fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) {
    if (win) {
        std::cout << std::endl << "Murder --------" << std::endl;
        std::cout << "Attacker: " << *attacker << "Defender: " << *defender << std::endl;
    } else {
        std::cout << std::endl << "Failed attack attempt --------" << std::endl;
        std::cout << "Attacker: " << *attacker << "Defender: " << *defender << std::endl;
    }
}

FileObserverBattlefield::FileObserverBattlefield() {
    _file.open("log/log.txt");
}

FileObserverBattlefield::~FileObserverBattlefield() {
    _file.close();
}

void FileObserverBattlefield::fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) {
    if (win) {
        _file << '\n' << "Murder --------" << '\n';
        _file << "Attacker: " << *attacker << "Defender: " << *defender << '\n';
    } else {
        _file << '\n' << "Failed attack attempt --------" << '\n';
        _file << "Attacker: " << *attacker << "Defender: " << *defender << '\n';
    }
}

void FileObserverBattlefield::battle_start(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& npcList) {
    _file << std::endl << "-------- Battle started --------" << std::endl;
    _file << "There are " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        _file << *npc;
    }
    _file << std::endl;
}

void FileObserverBattlefield::battle_end(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& npcList) {
    _file << std::endl << "-------- Battle ended --------" << std::endl;
    _file << "There was " << npcList.size() << " fighters." << std::endl;
    for (auto npc: npcList) {
        _file << *npc;
    }
    _file << std::endl;
}

FightManager& FightManager::get() {
    static FightManager inst;
    
    return inst;
}

void FightManager::push_event(FightMMA&& event) {
    std::lock_guard<std::shared_mutex> lock(_mtx);
    _events.push(event);
}

void FightManager::operator()() {
    auto start = std::chrono::system_clock::now();
    while(true) {
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - start).count() > 31) {
            break;
        }
        std::optional<FightMMA> event;
        {
            std::lock_guard<std::shared_mutex> lock(_mtx);
            if (!_events.empty()) {
                event = _events.back();
                _events.pop();
            }
        }
        
        if (event) {
            if (event->attacker->is_alive()) {
                if (event->defender->is_alive()) {  
                    event->defender->accept(visitors[event->attacker->type()], event->attacker);
                }
            }
        } else {
            std::this_thread::sleep_for(100ms);
        }  
    }
}
