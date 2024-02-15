<<<<<<< HEAD
#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock& Warlock::operator=(Warlock const &rhs) {
    this->_name = rhs._name;
    this->_title = rhs._title;
    return *this;
}

Warlock::Warlock(Warlock const &src) {
    *this = src;
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
    std::cout<<_name<<": This looks like another boring day."<<std::endl;
}

Warlock::~Warlock() {
    std::cout<<_name<<": My job here is done!"<<std::endl;
}

std::string const & Warlock::getName() const {
    return _name;
}

std::string const & Warlock::getTitle() const {
    return _title;
}

void Warlock::setTitle(std::string const &str) {
    _title = str;
}

void Warlock::introduce() const {
    std::cout<<_name<<": I am "<<_name<<", "<<_title<<"!"<<std::endl;
}
=======
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
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
