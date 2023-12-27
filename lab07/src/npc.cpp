#include "npc.h"

using namespace lab07;

std::mutex PRmutex;

int lab07::throw_dice() {
    return rand() % 6 + 1;
}

NPC::NPC(TypeNPC type, const Coord& coord, int attack_range, int move_range) :
_type{type}, _coord{coord}, _attack_range{attack_range}, _move_range{move_range}, _is_alive{true} {}

NPC::~NPC() {}

TypeNPC NPC::type() const {
    return _type;
}

const Coord& NPC::coord() const {
    std::lock_guard<std::mutex> lck(_mtx);
    return _coord;
}

bool NPC::is_alive() const {
    std::lock_guard<std::mutex> lck(_mtx);
    return _is_alive;
}

int NPC::attack_range() const {
    return _attack_range;
}

int NPC::move_range() const {
    return _move_range;
}

void NPC::save(std::ofstream& ofs) {
    ofs << _coord.first << ' ' << _coord.second << ' ' << type();
}

void NPC::load(std::ifstream& ifs) {
    int x, y, type;
    ifs >> x;
    ifs >> y;
    ifs >> type;
    _coord.first = x;
    _coord.second = y;
    _type = TypeNPC(type);
    _is_alive = true;
}

void NPC::move(int moveX, int moveY) {
    std::lock_guard<std::mutex> lck(_mtx);
    if ((_coord.first + moveX >= 0) && (_coord.first + moveX <= battlefield_size)) {
        _coord.first += moveX;
    }

    if ((_coord.second + moveY >= 0) && (_coord.second + moveY <= battlefield_size)) {
        _coord.second += moveY;
    }
}

void NPC::kill() {
    std::lock_guard<std::mutex> lck(_mtx);
    _is_alive = false;
}

void NPC::attach(const std::shared_ptr<Observer>& obs) {
    _views.push_back(obs);
}

void NPC::detach(const std::shared_ptr<Observer>& obs) {
    _views.remove(obs);
}

void NPC::notify(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win, int diceA, int diceD, int range_attack, double dist) const {
    for (auto obs : _views) {
        obs->fight(attacker, defender, win, diceA, diceD, range_attack, dist);
    }
}

std::ostream& lab07::operator<<(std::ostream& os, const NPC& npc) {
    switch (npc._type) {
        case ORC:
            os << "Orc: ";
            break;
        case KNIGHT_ERRANT:
            os << "Knight Errant: ";
            break;
        case BEAR:
            os << "Bear: ";
            break;
        default:
            throw std::logic_error("Unknown NPC type");
            break;
        }
    os << "{x = " << npc._coord.first << ", y = " << npc._coord.second << "} ";
    if (npc._is_alive) {
        os << "alive" << std::endl;
    } else {
        os << "dead" << std::endl;
    }
    return os;
}

double NPC::distance(const std::shared_ptr<NPC>& other) const{
    std::lock_guard<std::mutex> lck(_mtx);
    return pow((pow(_coord.first - other->_coord.first, 2) + pow(_coord.second - other->_coord.second, 2)), 0.5);
}

FileObserver::FileObserver() {
    _file.open("log/log.txt");
}

FileObserver::~FileObserver() {
    _file.close();
}

void OutputObserver::fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win, int diceA, int diceD, int range_attack, double dist) {
    std::lock_guard<std::mutex> lck(PRmutex);
    std::cout << "With dice attacker = " << diceA << '\t' << "With dice defender = " << diceD << std::endl;
    std::cout << "With attacker attack range = " << range_attack << '\t' << "With distance = " << dist << std::endl;
    if (win) {
        std::cout << std::endl << "Murder --------" << std::endl;
        std::cout << "Attacker: " << *attacker << "Defender: " << *defender << std::endl;
    } else {
        std::cout << std::endl << "Failed attack attempt --------" << std::endl;
        std::cout << "Attacker: " << *attacker << "Defender: " << *defender << std::endl;
    }
}

void FileObserver::fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win, int diceA, int diceD, int range_attack, double dist) {
    _file << "With dice attacker = " << diceA << '\t' << "With dice defender = " << diceD << std::endl;
    _file << "With attacker attack range = " << range_attack << '\t' << "With distance = " << dist << std::endl;
    if (win) {
        _file << '\n' << "Murder --------" << '\n';
        _file << "Attacker: " << *attacker << "Defender: " << *defender << '\n';
    } else {
        _file << '\n' << "Failed attack attempt --------" << '\n';
        _file << "Attacker: " << *attacker << "Defender: " << *defender << '\n';
    }
}
