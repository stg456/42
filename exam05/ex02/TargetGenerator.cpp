#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const &src) {
    *this = src;
}

TargetGenerator::TargetGenerator & operator = (TargetGenerator const &rhs) {
    _target = rhs.target;
    return (*this);
}

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* target) {
    if (target)
        _target[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &target) {
    if (_target.find(target) != _target.end())
        _target.erase(_target.find(target));
}

ATarget* TargetGenerator::createTarget(string const &target) {
    ATarget* tmp = NULL;
    if (_target.find(target) != _target.end())
        tmp = _target[target];
    return (tmp);
}
