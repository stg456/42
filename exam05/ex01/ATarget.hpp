#pragma once

#include <iostream>
//#include "Warlock.hpp"
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string _type;

    public:
        ATarget();
        ATarget(std::string const &type);
        ATarget(ATarget const &src);
        ATarget & operator = (ATarget const &rhs);
        virtual ~ATarget();

        std::string const & getType() const;
        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell const &spell) const;
};
