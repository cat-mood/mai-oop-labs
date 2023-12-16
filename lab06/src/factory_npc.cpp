#include "factory_npc.h"
#include <stdexcept>

using namespace lab06;

NPC* FactoryNPC::create(TypeNPC type, const std::string& name, const Coord& coord) {
    if (type == ORC) {
        return create_orc(name, coord);
    } else if (type == KNIGHT_ERRANT) {
        return create_knight_errant(name, coord);
    } else if (type == BEAR) {
        return create_bear(name, coord);
    } else {
        throw std::logic_error("Invalid type of NPC");
    }
}

NPC* FactoryNPC::create_orc(const std::string& name, const Coord& coord) {
    NPC* obj = new Orc(name, coord);
    return obj;
}

NPC* FactoryNPC::create_knight_errant(const std::string& name, const Coord& coord) {
    NPC* obj = new KnightErrant(name, coord);
    return obj;
}

NPC* FactoryNPC::create_bear(const std::string& name, const Coord& coord) {
    NPC* obj = new Bear(name, coord);
    return obj;
}
