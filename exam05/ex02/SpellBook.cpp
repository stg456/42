#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}

SpellBook::SpellBook(SpellBook const &src) {
    *this = src;
}

void SpellBook::learnSpell(ASpell*) {}

void SpellBook::forgetSpell() {std::string const &} {}

ASpell* SpellBook::createSpell(std::string const &) {}

