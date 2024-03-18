#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const &src) {
    *this = src;
}

SpellBook& SpellBook::operator=(SpellBook const &rhs) {
    this->spellB = rhs.spellB;
    return *this;
}

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {}


void SpellBook::learnSpell(ASpell* spell) {
    if (spell)
        spellB.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const &spellname) {
    if (spellB.find(spellname) != spellB.end())
        spellB.erase(spellB.find(spellname));
}

ASpell* SpellBook::createSpell(std::string const &spellname) {
    if (spellB.find(spellname) != spellB.end())
        return (spellB[spellname]);
    return (NULL);
}

