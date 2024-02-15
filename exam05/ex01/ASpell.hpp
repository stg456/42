#pragma once
#include "Warlock.hpp"

<<<<<<< HEAD
class Warlock;

class ATarget;
=======
class ATarget;

>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
class ASpell
{
    protected:
        std::string _name;
        std::string _effects;

    public:
<<<<<<< HEAD
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

=======
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
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
