#pragma once

#include "npc.h"

namespace lab06 {
    class FactoryNPC {
    public:
        FactoryNPC() = default;
        ~FactoryNPC() = default;
        NPC* create(TypeNPC type, const std::string& name, const Coord& coord = std::make_pair(-1, -1));
    private:
        NPC* create_orc(const std::string& name, const Coord& coord);
        NPC* create_knight_errant(const std::string& name, const Coord& coord);
        NPC* create_bear(const std::string& name, const Coord& coord);
    };
}
