#pragma once

#include "ASpell.hpp"

class ASpell;

class SpellBook
{
    private:
        SpellBook(SpellBook const &src);

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};
