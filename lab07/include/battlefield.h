#pragma once

#include <queue>
#include <shared_mutex>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <thread>
#include <optional>
#include <unordered_map>
#include <array>
#include "npc.h"
#include "bear.h"
#include "knight_errant.h"
#include "orc.h"

namespace lab07 {
    const double ESPILON = 0.001;

    using namespace std::chrono_literals;

    enum Commands {
        LOSE,
        WIN,
        BATTLE_START,
        BATTLE_END,
    };

    struct ObserverBattlefield;

    class Battlefield {
        friend class FightManager;
        public:
            Battlefield();

            friend std::ostream& operator<<(std::ostream& os, Battlefield& btf);

            void attach_obs(std::shared_ptr<ObserverBattlefield> observer);
            void detach_obs(std::shared_ptr<ObserverBattlefield> observer);
            void notify(int win);

            void fill_randomly(size_t seed, size_t orcs, size_t squrrels, size_t bears);
            void place_hero(std::shared_ptr<NPC> npc);
            void remove_hero(std::shared_ptr<NPC> npc);
            void remove_deadmen();

            std::list<std::shared_ptr<NPC>> npc();
            void battle();
        private:
            std::pair<int, int> _size;
            std::list<std::shared_ptr<NPC>> _npcList;
            std::list<std::shared_ptr<ObserverBattlefield>> _observers;
    };

    struct FightMMA {
        std::shared_ptr<NPC> attacker;
        std::shared_ptr<NPC> defender;
    };

    class FightManager {      
        private:
            std::queue<FightMMA> _events;
            std::shared_mutex _mtx;
        public:
            FightManager() = default;
            static FightManager& get();
            void push_event(FightMMA&& event);
            void operator()();
    };

    struct ObserverBattlefield: public std::enable_shared_from_this<ObserverBattlefield> {
        virtual void battle_start(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& _npcList) = 0;
        virtual void fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) = 0;
        virtual void battle_end(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& _npcList) = 0;
    };

    class OutputObserverBattlefield : public ObserverBattlefield {
        public:
            void battle_start(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& _npcList) override;
            void fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) override;
            void battle_end(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& _npcList) override;
    };

    class FileObserverBattlefield : public ObserverBattlefield {
        public:
            FileObserverBattlefield();
            ~FileObserverBattlefield();
            void battle_start(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& _npcList) override;
            void fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win) override;
            void battle_end(const std::pair<int,int>& size, const std::list<std::shared_ptr<NPC>>& _npcList) override;
        private:
            std::ofstream _file;
    };
}
