#pragma once
#include "Warlock.hpp"

class Warlock;

class ASpell;

class ATarget
{
    protected:
        std::string _type;

    public:
        ATarget(std::string type);
        ATarget(Atrget const &src);
        ATarget & operator = (Atarget const &rhs);
        virtual ~ATarget();

        std::string getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell const &spell) const;
};
