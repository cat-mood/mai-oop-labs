#pragma once

#include "npc.h"

namespace lab07 {
    class KnightErrant : public NPC {
        public:
            KnightErrant(int x, int y);

            virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) override;
    };

    class VisitorKnightErrant : public Visitor {
        public: 
            bool visit(const std::shared_ptr<Orc>& defender) override;
            bool visit(const std::shared_ptr<Bear>& defender) override;
            bool visit(const std::shared_ptr<KnightErrant>& defender) override;
    };

    class KnightErrantFactory : public Factory {
        public:
            std::shared_ptr<NPC> create(int x, int y) override;
            std::shared_ptr<NPC> create(std::istream& is) override;
            std::shared_ptr<NPC> create(std::ifstream& ifs) override;
    };
}
