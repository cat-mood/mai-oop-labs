#include "npc.h"

using namespace lab06;

NPC::NPC(const std::string& name, const Coord& coord) : _name{name}, _coord{coord} {}

NPC::~NPC() {}

TypeNPC NPC::type() const {
    return _type;
}

const std::string& NPC::name() const {
    return _name;
}

const Coord& NPC::coord() const {
    return _coord;
}

Coord& NPC::coord() {
    return _coord;
}

void NPC::attach(Observer* obs) {
    _views.push_back(obs);
}

void NPC::detach(Observer* obs) {
    _views.remove(obs);
}

void NPC::notify() const {
    for (auto obs : _views) {
        obs->update(this);
    }
}

const std::string& NPC::killer_name() const {
    return _killer_name;
}

std::string& NPC::killer_name() {
    return _killer_name;
}

Orc::Orc(const std::string& name, const Coord& coord) : NPC(name, coord) {
    _type = ORC;
}

Orc::~Orc() {}

bool Orc::can_kill(NPC* other) const {
    if (other->type() == BEAR) {
        return true;
    }
    return false;
}

KnightErrant::KnightErrant(const std::string& name, const Coord& coord) : NPC(name, coord) {
    _type = KNIGHT_ERRANT;
}

KnightErrant::~KnightErrant() {}

bool KnightErrant::can_kill(NPC* other) const {
    if (other->type() == ORC) {
        return true;
    }
    return false;
}

Bear::Bear(const std::string& name, const Coord& coord) : NPC(name, coord) {
    _type = BEAR;
}

Bear::~Bear() {}

bool Bear::can_kill(NPC* other) const {
    if (other->type() == KNIGHT_ERRANT) {
        return true;
    }
    return false;
}

double lab06::distance(const Coord& first, const Coord& second) {
    int x = std::abs(first.first - second.first);
    int y = std::abs(first.second - second.second);
    return std::sqrt(x*x + y*y);
}

Observer::Observer(std::map<Coord, NPC*> npcs) {
    for (auto [coord, npc] : npcs) {
        npc->attach(this);
    }
}

FileObserver::FileObserver(std::map<Coord, NPC*> npcs, const std::string& filename) : Observer(npcs) {
    _file.open(filename);
}

FileObserver::~FileObserver() {
    _file.close();
}

void FileObserver::update(const NPC* npc) {
    _file << npc->name() << " killed by " << npc->killer_name() << '\n';
}

OutputObserver::OutputObserver(std::map<Coord, NPC*> npcs) : Observer(npcs) {}

void OutputObserver::update(const NPC* npc) {
    std::cout << npc->name() << " killed by " << npc->killer_name() << std::endl;
}
