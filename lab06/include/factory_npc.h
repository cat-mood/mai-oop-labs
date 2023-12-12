#pragma once

#include "npc.h"
#include <unordered_map>

namespace lab06 {
    class FactoryNPC {
    public:
        FactoryNPC() = default;
        ~FactoryNPC() = default;
        NPC* create(TypeNPC type, const std::string& name);
    private:
        NPC* create_orc(const std::string& name);
        NPC* create_knight_errant(const std::string& name);
        NPC* create_bear(const std::string& name);
    };
}
