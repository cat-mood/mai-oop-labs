#pragma once

#include <string>
#include <list>
#include <cmath>
#include <map>
#include <iostream>
#include <fstream>

namespace lab06 {
    using Coord = std::pair<int, int>;

    double distance(const Coord& first, const Coord& second);

    enum TypeNPC {
        ORC,
        KNIGHT_ERRANT,
        BEAR
    };

    class Observer;

    class NPC {
    public:
        NPC(const std::string& name, const Coord& coord);
        TypeNPC type() const;
        const std::string& name() const;
        const Coord& coord() const;
        Coord& coord();
        const std::string& killer_name() const;
        std::string& killer_name();
        void attach(Observer* obs);
        void detach(Observer* obs);
        void notify() const;
        virtual bool can_kill(NPC* other) const = 0;
        virtual ~NPC();
    protected:
        TypeNPC _type;
        std::string _name;
        Coord _coord;
        std::string _killer_name;
        std::list<Observer*> _views;
    };

    class Orc : public NPC {
    public:
        Orc(const std::string& name, const Coord& coord);
        virtual ~Orc();
        virtual bool can_kill(NPC* other) const override;
    };

    class KnightErrant : public NPC {
    public:
        KnightErrant(const std::string& name, const Coord& coord);
        virtual ~KnightErrant();
        virtual bool can_kill(NPC* other) const override;
    };

    class Bear : public NPC {
    public:
        Bear(const std::string& name, const Coord& coord);
        virtual ~Bear();
        virtual bool can_kill(NPC* other) const override;
    };

    class Observer {
    public:
        Observer(std::map<Coord, NPC*> npcs);
        ~Observer() = default;
        virtual void update(const NPC* npc) = 0;
    };

    class FileObserver : public Observer {
    public:
        FileObserver(std::map<Coord, NPC*> npcs, const std::string& filename);
        ~FileObserver();
        virtual void update(const NPC* npc) override;
    private:
        std::ofstream _file;
    };

    class OutputObserver : public Observer {
    public:
        OutputObserver(std::map<Coord, NPC*> npcs);
        ~OutputObserver() = default;
        virtual void update(const NPC* npc) override;
    };
}
