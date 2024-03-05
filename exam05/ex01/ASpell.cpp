#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string title) : _name(name), _title(title) {}

ASpell::~ASpell() {}

ASpell::ASpell(ASpell const &src) {
    *this = src;
}

ASpell& ASpell::operator = (ASpell const &rhs) {
    _name = rhs.getName();
    _effects = rhs.getEffects();
    return *this;
}

std::string ASpell::getName() const {
    return (_name);
}

std::string ASpell::getEffects() const {
    return (_effects);
}

void ASpell::launch(ATarget const &target) const {
    target.getHitBySpell(*this);
}
