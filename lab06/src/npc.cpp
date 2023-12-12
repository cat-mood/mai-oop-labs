#include "npc.h"

using namespace lab06;

NPC::NPC(const std::string& name) : _name{name} {}

NPC::~NPC() {}

TypeNPC NPC::type() const {
    return _type;
}

const std::string& NPC::name() const {
    return _name;
}

Orc::Orc(const std::string& name) : NPC(name) {
    _type = ORC;
}

Orc::~Orc() {}

bool Orc::can_kill(NPC* other) const {
    if (other->type() == BEAR) {
        return true;
    }
    return false;
}

KnightErrant::KnightErrant(const std::string& name) : NPC(name) {
    _type = KNIGHT_ERRANT;
}

KnightErrant::~KnightErrant() {}

bool KnightErrant::can_kill(NPC* other) const {
    if (other->type() == ORC) {
        return true;
    }
    return false;
}

Bear::Bear(const std::string& name) : NPC(name) {
    _type = BEAR;
}

Bear::~Bear() {}

bool Bear::can_kill(NPC* other) const {
    if (other->type() == KNIGHT_ERRANT) {
        return true;
    }
    return false;
}
