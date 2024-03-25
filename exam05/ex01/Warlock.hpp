#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

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
        void setTitle(std::string const &);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spellname);
        void launchSpell(std::string spellname, ATarget const &target);
};

