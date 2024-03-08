#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(std::string name, std::string title): _name(name), _title(title) {
    std::cout<<_name<<": This looks like another boring day."<<std::endl;
}

Warlock::~Warlock() {
    std::cout<<_name<<": My job here is done!"<<std::endl;
}

Warlock::Warlock(Warlock const &src) {
    *this = src;
}

Warlock& Warlock::operator = (Warlock const &rhs) {
    this->_name = rhs.getName();
    this->_title = rhs.getTitle();
    return *this;
}

std::string const & Warlock::getName() const {
    return (_name);
}

std::string const & Warlock::getTitle() const {
    return (_title);
}

void Warlock::setTitle(std::string const &str) {
     _title = str;
}

void Warlock::introduce() const {
    std::cout<<_name<<": I am "<<_name<<", "<<_title<<"!"<<std::endl;
}

void Warlock::learnSpell(ASpell*spell) {
    if (spell)
        _book.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string spellname) {
    std::map<std::string, ASpell*>::iterator it = _book.find(spellname);
    if (it != _book.end())
        delete it->second;
    _book.erase(spellname);
}

void Warlock::launchSpell(std::string spellname, ATarget const &target) {
    ASpell* spell = _book[spellname];
    if (spell)
        spell->launch(target);
}
