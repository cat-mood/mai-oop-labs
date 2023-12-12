#pragma once

#include <string>

namespace lab06 {
    enum TypeNPC {
        ORC,
        KNIGHT_ERRANT,
        BEAR
    };

    class NPC {
    public:
        NPC(const std::string& name);
        TypeNPC type() const;
        const std::string& name() const;
        virtual bool can_kill(NPC* other) const = 0;
        virtual ~NPC();
    protected:
        TypeNPC _type;
        std::string _name;
    };

    class Orc : public NPC {
    public:
        Orc(const std::string& name);
        virtual ~Orc();
        virtual bool can_kill(NPC* other) const override;
    };

    class KnightErrant : public NPC {
    public:
        KnightErrant(const std::string& name);
        virtual ~KnightErrant();
        virtual bool can_kill(NPC* other) const override;
    };

    class Bear : public NPC {
    public:
        Bear(const std::string& name);
        virtual ~Bear();
        virtual bool can_kill(NPC* other) const override;
    };
}
