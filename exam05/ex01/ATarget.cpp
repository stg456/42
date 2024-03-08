#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type): _type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(ATarget const &src) {
    *this = src;
}

ATarget& ATarget::operator = (ATarget const &rhs) {
    _type = rhs._type;
    return (*this);
}

std::string const & ATarget::getType() const {
    return (this->_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const {
    std::cout<<this->_type<<" has been "<<spell.getEffects()<<std::endl;
}
