#include "Warlock.hpp"

Warlock::Warlock() {}

<<<<<<< HEAD
Warlock& Warlock::operator=(Warlock const &rhs) {
    this->_name = rhs._name;
    this->_title = rhs._title;
    return *this;
=======
Warlock::~Warlock() {
    std::cout << _name << ": My job here is done!" << std::endl;
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
}

Warlock::Warlock(Warlock const &src) {
    *this = src;
}

<<<<<<< HEAD
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
=======
Warlock & Warlock::operator = (Warlock const &rhs) {
    _name = rhs._name;
    _title = rhs._title;
    return *this;
}

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

std::string const Warlock::getName() const {
    return (_name);
}

std::string const Warlock::getTitle() const {
    return (_title);
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
}

void Warlock::setTitle(std::string const &str) {
    _title = str;
}

void Warlock::introduce() const {
<<<<<<< HEAD
    std::cout<<_name<<": I am "<<_name<<", "<<_title<<"!"<<std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell)
        if (_spellBook.find(spell->getName()) == _spellBook.end())
            _spellBook[spell.getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spellName) {
    if (_spellBook.find(spellName) != _spellBook.end())
        spellBook.erase(_spellBook.find(spellName));
}

void Warlock::launchSpell(std::string spellName, ATarget const &target) {
    if (_spellBook.find(spellName) != _spellBook.end())
        _spellBook[spellName]->launch(target);
=======
    std::cout<< _name<<": I am "<<_name<<", "<<_title<<"!"<< std::endl;
>>>>>>> a33c94c461bc0e42ae186abf3f786592899d6c81
}
