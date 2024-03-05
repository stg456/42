#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        std::map<std::string, ASpell*> _SpellBook;

        Warlock();
        Warlock(Warlock const &src);
        Warlock & operator = (Warlock const &rhs);

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
};

