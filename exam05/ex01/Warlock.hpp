#pragma once
#include <iostream>
<<<<<<< HEAD
#include <map>
#include "ASpell.hpp"
=======
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81

class Warlock
{
    private:
        std::string _name;
        std::string _title;
<<<<<<< HEAD
        std::map<std::string, aspell*> _spellBook;

        Warlock();
        Warlock& operator=(Warlock const &rhs);
        Warlock(Warlock const &src);

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        std::string const & getName() const;
        std::string const & getTitle() const;
        void setTitle(std::string const &str);
        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spellName);
        void launchSpell(std::string spellName, ATarget const &target);
=======

        Warlock();
        Warlock(Warlock const &src);
        Warlock& operator = (Warlock const &rhs);
    
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        std::string const getName() const;
        std::string const getTitle() const;
        void setTitle(std::string const &str);
        void introduce() const;
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
};
