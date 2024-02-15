#pragma once
#include "ASpell.hpp"

class Fwoosh : publis ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();
        ASpell* clone() const;
};

