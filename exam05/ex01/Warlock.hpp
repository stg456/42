#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"


class Warlock
{
    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell*> book;

        Warlock();
        Warlock(Warlock const &src);
        Warlock& operator=(Warlock const &rhs);

    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
        
        std::string const & getName() const;
        std::string const & getTitle() const;
        void setTitle(std::string const &src);
        void introduce() const;

        void learnSpell(ASpell*spell);
        void forgetSpell(std::string str);
        void launchSpell(std::string spellname, ATarget const &target);
};

