#include "knight_errant.h"

using namespace lab07;

KnightErrant::KnightErrant(int x, int y) : 
    NPC(KNIGHT_ERRANT, std::make_pair(x, y), RangeMove::ATTACK_RANGE_KNIGHT, RangeMove::MOVE_RANGE_KNIGHT) {}

int KnightErrant::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) {
    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<KnightErrant> defender = std::dynamic_pointer_cast<KnightErrant>(npc_ptr);
    int diceA = throw_dice();
    int diceD = throw_dice();
    
    if (attacker_visitor->visit(defender)) {
        if (diceA > diceD) {
            this->notify(attacker, defender, true, diceA, diceD, _attack_range, attacker->distance(defender));
            this->kill();
            return true;
        }
    }
    return false;
}

bool VisitorKnightErrant::visit(const std::shared_ptr<Bear>& defender) {
    return false;
}
bool VisitorKnightErrant::visit(const std::shared_ptr<Orc>& defender) {
    return true;
}
bool VisitorKnightErrant::visit(const std::shared_ptr<KnightErrant>& defender) {
    return false;
}


std::shared_ptr<NPC> KnightErrantFactory::create(int x, int y) {
    std::shared_ptr<NPC> result = std::make_shared<KnightErrant>(x, y);
    std::shared_ptr<OutputObserver> obsO = std::make_shared<OutputObserver>();
    std::shared_ptr<FileObserver> obsF = std::make_shared<FileObserver>();
    result->attach(obsO);
    result->attach(obsF);
    return result;
}

std::shared_ptr<NPC> KnightErrantFactory::create(std::istream& is) {
    std::pair<int,int> tmp;
    is >> tmp.first; is >> tmp.second;
    std::shared_ptr<NPC> result = std::make_shared<KnightErrant>(tmp.first, tmp.second);
    std::shared_ptr<OutputObserver> obsO = std::make_shared<OutputObserver>();
    std::shared_ptr<FileObserver> obsF = std::make_shared<FileObserver>();
    result->attach(obsO);
    result->attach(obsF);
    return result;
}

std::shared_ptr<NPC> KnightErrantFactory::create(std::ifstream& ifs) {
    int x; int y; int type;
    ifs >> x; ifs >> y; ifs >> type;
    std::shared_ptr<NPC> result = std::make_shared<KnightErrant>(x,y);
    std::shared_ptr<OutputObserver> obsO = std::make_shared<OutputObserver>();
    std::shared_ptr<FileObserver> obsF = std::make_shared<FileObserver>();
    result->attach(obsO);
    result->attach(obsF);
    return result;
}
