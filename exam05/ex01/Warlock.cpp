#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(Warlock const &src) {
    *this = src;
}

Warlock& Warlock::operator=(Warlock const &rhs) {
    this->name = rhs.name;
    this->title = rhs.title;
    return (*this);
}

Warlock::Warlock(std::string const &name, std::string const &title) {
    this->name = name;
    this->title = title;
    std::cout<<this->name<<": This looks like another boring day.\n";
}

Warlock::~Warlock() {
    std::cout<<this->name<<": My job here is done!\n";
}

std::string const & Warlock::getName() const {
    return (name);
}

std::string const & Warlock::getTitle() const {
    return (title);
}

void Warlock::setTitle(std::string const &src) {
    this->title = src;
}

void Warlock::introduce() const {
    std::cout<<this->name<<": I am "<<this->name<<", "<<this->title<<"!\n";
}

void Warlock::learnSpell(ASpell* spell) {
    if (spell)
        book.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void Warlock::forgetSpell(std::string spellname) {
    if (book.find(spellname) != book.end())
        book.erase(book.find(spellname));
}
    
void Warlock::launchSpell(std::string spellname, ATarget const &target) {
    if (book.find(spellname) != book.end())
        book[spellname]->launch(target);
}
