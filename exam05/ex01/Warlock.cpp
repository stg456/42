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
}
