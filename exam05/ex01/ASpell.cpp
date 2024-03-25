#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects): name(name), effects(effects) {}

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

//        virtual ASpell* clone() const;

void ASpell::launch(ATarget const &target) const {
    target.getHitBySpell(*this);
}

