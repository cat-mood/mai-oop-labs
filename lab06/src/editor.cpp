#include "editor.h"

using namespace lab06;

Editor::Editor() {}

Editor::~Editor() {
    for (auto [coord, npc] : _map) {
        delete npc;
    }
}

void Editor::place(NPC* npc, const Coord& coord) {
    if (_map.find(coord) != _map.end()) {
        throw std::logic_error("There is already NPC at this coordinates");
    }
    npc->coord() = coord;
    _map[coord] = npc;
}

NPC* Editor::unplace(const Coord& coord) {
    if (_map.find(coord) == _map.end()) {
        throw std::logic_error("There is no NPC");
    }
    NPC* npc = _map[coord];
    _map.erase(coord);
    npc->coord() = std::make_pair(-1, -1);
    return npc;
}

void Editor::create_NPC(TypeNPC type, const std::string& name, const Coord& coord) {
    NPC* npc = _factory.create(type, name);
    if (_names.find(npc->name()) != _names.end()) {
        throw std::logic_error("Name of NPC must be unique");
    }
    _names.insert(npc->name());
    place(npc, coord);
}

void Editor::delete_NPC(const Coord& coord) {
    NPC* npc = unplace(coord);
    _names.erase(npc->name());
    delete npc;
}

void Editor::delete_NPC(NPC* npc) {
    this->delete_NPC(npc->coord());
}

void Editor::move_NPC(const Coord& old_c, const Coord& new_c) {
    NPC* npc = unplace(old_c);
    place(npc, new_c);
}

void Editor::save_to_file(const std::string& path) const {
    std::ofstream file(path);
    if (!file) {
        throw std::runtime_error("Can't open file");
    }
    file << this->count_npc() << '\n';
    for (const auto& [key, value] : _map) {
        NPC* npc = value;
        file << key.first << ' ' << key.second << '\n';
        file << npc->type() << ' ' << npc->name() << '\n';
    }
    file.close();
}

void Editor::load_from_file(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Can't open file");
    }
    int n;
    file >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        file >> x >> y;
        Coord coord = std::make_pair(x, y);
        int type;
        std::string name;
        file >> type >> name;
        this->create_NPC((TypeNPC) type, name, coord);
    }
    file.close();
}

void Editor::print_map() const {
    for (const auto& [key, value] : _map) {
        NPC* npc = value;
        std::cout << "x: " << key.first << " y: " << key.second << '\t';
        print_NPC(npc);
        std::cout << std::endl;
    }
}

void Editor::print_NPC(NPC* npc) const {
    TypeNPC type = npc->type();
    if (type == ORC) {
        std::cout << "Orc";
    } else if (type == KNIGHT_ERRANT) {
        std::cout << "Knight errant";
    } else if (type == BEAR) {
        std::cout << "Bear";
    }
    std::cout << " '" << npc->name() << "'";
}

int Editor::count_npc() const {
    return _names.size();
}

void Editor::fight(int _distance) {
    if (_distance < 0) throw std::logic_error("Distance can't be negative");
    std::unordered_set<NPC*> died;
    FileObserver fobs(_map, "log.txt");
    OutputObserver oobs(_map);
    for (auto [acoord, attacker] : _map) {
        for (auto [dcoord, defender] : _map) {
            if (attacker == defender) continue;
            bool success = attacker->can_kill(defender) 
            && (distance(attacker->coord(), defender->coord()) <= _distance);
            if (success) {
                died.insert(defender);
                defender->killer_name() = attacker->name();
            }
        }
    }
    for (auto npc : died) {
        npc->notify();
        this->delete_NPC(npc);
    }
    for (auto [coord, npc] : _map) {
        npc->detach(&fobs);
        npc->detach(&oobs);
    }
}
