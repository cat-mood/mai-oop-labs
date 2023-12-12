#include "factory_npc.h"
#include <stdexcept>

using namespace lab06;

NPC* FactoryNPC::create(TypeNPC type, const std::string& name) {
    if (type == ORC) {
        return create_orc(name);
    } else if (type == KNIGHT_ERRANT) {
        return create_knight_errant(name);
    } else if (type == BEAR) {
        return create_bear(name);
    } else {
        throw std::logic_error("Invalid type of NPC");
    }
}

NPC* FactoryNPC::create_orc(const std::string& name) {
    NPC* obj = new Orc(name);
    return obj;
}

NPC* FactoryNPC::create_knight_errant(const std::string& name) {
    NPC* obj = new KnightErrant(name);
    return obj;
}

NPC* FactoryNPC::create_bear(const std::string& name) {
    NPC* obj = new Bear(name);
    return obj;
}
