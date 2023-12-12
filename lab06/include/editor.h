#pragma once

#include <unordered_set>
#include <unordered_map>
#include <string>
#include <array>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "factory_npc.h"
#include "npc.h"

namespace lab06 {
    using Coord = std::pair<int, int>;

    class Editor {
    public:
        Editor();
        ~Editor();
        void create_NPC(TypeNPC type, const std::string& name, const Coord& coord);
        void delete_NPC(const Coord& coord);
        void move_NPC(const Coord& old_c, const Coord& new_c);
        void save_to_file(const std::string& path) const;
        void load_from_file(const std::string& path);
        void print_map() const;
        int count_npc() const;
    private:
        static const int _width = 500;
        static const int _height = 500;
        std::unordered_set<std::string> _names;
        std::array<std::array<NPC*, _height>, _width> _map;     // x - width, y - height
        FactoryNPC _factory;

        void place(NPC* npc, const Coord& coord);
        NPC* unplace(const Coord& coord);
        void print_NPC(NPC* npc) const;
    };
}
