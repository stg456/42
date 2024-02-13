#include "Warlock.cpp"

Warlock::Warlock() {}

Warlock::Warlock(Warlock const &obj) {}

Warlock::Warlock & operator = (Warlock const & rhs) {}

Warlock::Warlock(std::string name, std::string title) {}

Warlock::~Warlock() {
    std::cout <<_name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const {}

std::string const & Warlock::getTitle()const {}

void Warlock::setTitle(std::string const & str) {}

void Warlock::introduce() const{}