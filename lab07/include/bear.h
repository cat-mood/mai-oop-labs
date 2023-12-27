#pragma once

#include "npc.h"

namespace lab07 {
    class Bear : public NPC {
        public:
            Bear(int x, int y);

            virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) override;
    };

    class VisitorBear : public Visitor {
        public: 
            bool visit(const std::shared_ptr<Orc>& defender) override;
            bool visit(const std::shared_ptr<Bear>& defender) override;
            bool visit(const std::shared_ptr<KnightErrant>& defender) override;
    };

    class BearFactory : public Factory {
        public:
            std::shared_ptr<NPC> create(int x, int y) override;
            std::shared_ptr<NPC> create(std::istream& is) override;
            std::shared_ptr<NPC> create(std::ifstream& ifs) override;
    };
}

