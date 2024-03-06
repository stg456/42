#pragma once

#include "ASpell.hpp"
#include <map>

// class ASpell;

class SpellBook
{
    private:
        SpellBook(SpellBook const &src);
        SpellBook & operator = (SpellBook const &rhs);
        std::map<std::string, ASpell*> _SpellBook;

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};

