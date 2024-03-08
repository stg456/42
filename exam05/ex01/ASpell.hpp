#pragma once

#include <iostream>
//#include "Warlock.hpp"
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
        std::string _name;
        std::string _effects;

    public:
        ASpell();
        ASpell (std::string const &name, std::string const &effects);
        ASpell (ASpell const &src);
        ASpell & operator =(ASpell const &rhs);
        virtual ~ASpell();

        std::string const & getName() const;
        std::string const & getEffects() const;
        virtual ASpell* clone() const = 0;
        void launch(ATarget const &target) const;
};
