#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string type) : type(type) {}

ATarget::ATarget(ATarget const &src) {
    *this = src;
}

ATarget& ATarget::operator=(ATarget const &rhs) {
    this->type = rhs.type;
    return *this;
}

ATarget::~ATarget() {}

std::string ATarget::getType() const {
    return (type);
}

//        virtual ATarget* clone() const = 0;

void ATarget::getHitBySpell(ASpell const &spell) const {
    std::cout<<type<<" has been "<<spell.getEffects()<<"!\n";
}

