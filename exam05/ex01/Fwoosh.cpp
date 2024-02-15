#include "Fwoosh.hpp"

Fwoosh::Fwoosh() {}

Fwoosh::~Fwoosh() {}

ASpell* Fwoosh::clone() const {
    return (new Fwoosh());
}
