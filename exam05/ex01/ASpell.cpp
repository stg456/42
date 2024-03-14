#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string name, std::string effects) {
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(ASpell const &src) {
    *this = src;
}

ASpell& ASpell::operator=(ASpell const &rhs) {
    this->name = rhs.name;
    this->effects = rhs.effects;
    return (*this);
}

ASpell::~ASpell() {}


std::string ASpell::getName() const {
    return (name);
}

std::string ASpell::getEffects() const {
    return (effects);
}

void ASpell::launch(ATarget const &src) const {
    src.getHitBySpell(*this);
}

