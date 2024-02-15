#pragma once
#include "Warlock.hpp"

class Warlock;

class ATarget;
class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
        ASpell(std::sring name, std::string Effects);
        ASpell(ASpell const &src);
        ASpell & operator = (ASpell const & rhs);
        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;
        virtual ASpell* clone() const = 0;
        void launch(ATarget const & target) const;
};


//class Aspell;
//class ATarget
//{
//    protected:
//        std::string _type;
//
//    public:
//        ATarget(std::string type);
//        ATarget(Atrget const &src);
//        ATarget & operator = (Atarget const &rhs);
//        virtual ~ATarget();
//
//        std::string getType() const;
//        virtual ATarget* clone() const = 0;
//        void getHitBySpell(ASpell const &spell) const;      
//};

