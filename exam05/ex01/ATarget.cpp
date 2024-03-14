#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string type) {
    this->type = type;
}

ATarget::ATarget(ATarget const &src) {
    *this = src;
}

ATarget& ATarget::operator=(ATarget const &rhs) {
    this->type = rhs.type;
    return (*this);
}

ATarget::~ATarget() {}

std::string ATarget::getType() const {
    return (type);
}

void ATarget::getHitBySpell(ASpell const &spell) const {
    std::cout<<this->type<<" has been "<<spell.getEffects()<<"!\n";
}

