#pragma once

#include <string>
#include <list>
#include <cmath>
#include <map>
#include <iostream>
#include <fstream>
#include <mutex>
#include <memory>

namespace lab07 {
    const int battlefield_size = 100;

    using Coord = std::pair<int, int>;

    enum RangeMove {
        ATTACK_RANGE_BEAR = 10,
        ATTACK_RANGE_ORC = 10,
        ATTACK_RANGE_KNIGHT = 10,
        MOVE_RANGE_BEAR = 5,
        MOVE_RANGE_ORC = 20,
        MOVE_RANGE_KNIGHT = 30
    };

    enum TypeNPC {
        ORC,
        KNIGHT_ERRANT,
        BEAR
    };

    int throw_dice();

    class Observer;
    class Orc;
    class Bear;
    class KnightErrant;

    class Visitor {
    friend class NPC;
    public: 
        virtual bool visit(const std::shared_ptr<Orc>& defender) = 0;
        virtual bool visit(const std::shared_ptr<Bear>& defender) = 0;
        virtual bool visit(const std::shared_ptr<KnightErrant>& defender) = 0;
    };

    class NPC : public std::enable_shared_from_this<NPC> {
    public:
        NPC(TypeNPC type, const Coord& coord, int attack_range, int move_range);
        TypeNPC type() const;
        const Coord& coord() const;
        bool is_alive() const;
        int attack_range() const;
        int move_range() const;
        void attach(const std::shared_ptr<Observer>& obs);
        void detach(const std::shared_ptr<Observer>& obs);
        void notify(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win, int diceA, int diceD, int range_attack, double dist) const;
        virtual int accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) = 0;
        friend std::ostream& operator<<(std::ostream& os, const NPC& npc);
        void kill();
        void move(int moveX, int moveY);
        void save(std::ofstream &ofs);
        void load(std::ifstream &ifs);
        double distance(const std::shared_ptr<NPC>& other) const;
        virtual ~NPC();
    protected:
        TypeNPC _type;
        Coord _coord;
        std::list<std::shared_ptr<Observer>> _views;
        bool _is_alive;
        int _attack_range;
        int _move_range;
    private:
        mutable std::mutex _mtx;
    };

    class Observer {
    public:
        virtual void fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win, int diceA, int diceD, int range_attack, double dist) = 0;
    };

    class FileObserver : public Observer {
    public:
        FileObserver();
        ~FileObserver();
        void fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win, int diceA, int diceD, int range_attack, double dist) override;
    private:
        std::ofstream _file;
    };

    class OutputObserver : public Observer {
    public:
        void fight(const std::shared_ptr<NPC>& attacker, const std::shared_ptr<NPC>& defender, bool win, int diceA, int diceD, int range_attack, double dist) override;
    };

    class Factory {
    public:
        virtual std::shared_ptr<NPC> create(int x, int y) = 0;
        virtual std::shared_ptr<NPC> create(std::istream &is) = 0;
        virtual std::shared_ptr<NPC> create(std::ifstream &ifs) = 0;
        ~Factory() = default;
    };
}
