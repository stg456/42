#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const &src) {
    *this = src;
}

TargetGenerator& TargetGenerator::operator=(TargetGenerator const &rhs) {
    this->targetB = rhs.targetB;
    return *this;
}

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}


void TargetGenerator::learnTargetType(ATarget* target) {
    if (target)
        targetB.insert(std::pair<std::string, ATarget*>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &target) {
    if (targetB.find(target) != targetB.end())
        targetB.erase(targetB.find(target));
        
}

ATarget* TargetGenerator::createTarget(std::string const &target) {
    if (targetB.find(target) != targetB.end())
        return (targetB[target]);
    return (NULL);
}

