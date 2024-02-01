#pragma once
#include "Warlock.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell(std::string name, std::string effects);
        virtual ~ASpell();
        std::string getName(std::string const &src);
        std::string getEffects(std::string const &src);
        virtual void clone() const = 0;
};

class ASpell;

class ATarget
{
    protected:
        std::string _target;

    public:
        ATarget(std::string target);
        virtual ~ATarget();
        std::string getTarget(std::string &target);
        virtual getHitsBySpell() const = 0;
}
