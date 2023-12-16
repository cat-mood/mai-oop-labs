#pragma once

#include <string>
#include <cmath>

namespace lab06 {
    using Coord = std::pair<int, int>;

    double distance(const Coord& first, const Coord& second);

    enum TypeNPC {
        ORC,
        KNIGHT_ERRANT,
        BEAR
    };

    class NPC {
    public:
        NPC(const std::string& name, const Coord& coord);
        TypeNPC type() const;
        const std::string& name() const;
        const Coord& coord() const;
        Coord& coord();
        virtual bool can_kill(NPC* other) const = 0;
        virtual ~NPC();
    protected:
        TypeNPC _type;
        std::string _name;
        Coord _coord;
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
}
