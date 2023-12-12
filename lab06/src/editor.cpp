#include "editor.h"

using namespace lab06;

Editor::Editor() {
    for (int i = 0; i < _height; ++i) {
        for (int j = 0; j < _width; ++j) {
            _map[i][j] = nullptr;
        }
    }
}

Editor::~Editor() {}

void Editor::place(NPC* npc, const Coord& coord) {
    if (_map[coord.first][coord.second] != nullptr) {
        throw std::logic_error("There is already NPC at this coordinates");
    }
    _map[coord.first][coord.second] = npc;
}

NPC* Editor::unplace(const Coord& coord) {
    if (_map[coord.first][coord.second] == nullptr) {
        throw std::logic_error("There is no NPC");
    }
    NPC* npc = _map[coord.first][coord.second];
    _map[coord.first][coord.second] = nullptr;
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
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            NPC* npc = _map[i][j];
            if (npc == nullptr) {
                continue;
            }
            file << i << ' ' << j << '\n';
            file << npc->type() << ' ' << npc->name() << '\n';
        }
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
    for (int i = 0; i < _width; ++i) {
        for (int j = 0; j < _height; ++j) {
            NPC* npc = _map[i][j];
            if (npc == nullptr) {
                continue;
            }
            std::cout << "x: " << i << " y: " << j << "\t";
            print_NPC(npc);
            std::cout << std::endl;
        }
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
