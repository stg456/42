#include "BrickWall.hpp"

BrickWall::BrickWall() : BrickWall("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

ATarget* BrickWall::clone() const {
    return (new BrickWall());
}

