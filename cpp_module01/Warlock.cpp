#include "Warlock.hpp" 

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->getName() << ": My job here is done!" << std::endl;
    for (std::map<std::string, ASpell*>::iterator it = this->_spell.begin(); it != this->_spell.end(); it++)
    {
        delete it->second;
    }
    _spell.clear();
}

Warlock & Warlock::operator=(Warlock const &src)
{
    if (this != &src)
    {
        _name = src._name;
        _title = src._title;
    }
    return (*this);
}

Warlock::Warlock(Warlock const &src)
{
    *this = src;
}

void Warlock::introduce() const
{
    std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void Warlock::setTitle(const std::string &title)
{
    _title = title;
}

std::string const & Warlock::getName() const
{
    return (_name);
}

std::string const & Warlock::getTitle() const
{
    return (_title);
}


void Warlock::learnSpell(ASpell* new_spell)
{
    if (new_spell)
        this->_spell[new_spell->getName()] = new_spell->clone();
}

void Warlock::forgetSpell(std::string spell_name)
{
    std::map<std::string, ASpell*>::iterator it = this->_spell.find(spell_name);
    if (it != this->_spell.end())
    {
        delete it->second;
        _spell.erase(it);
    }
}

void Warlock::launchSpell(std::string spell_name, ATarget &target)
{
    std::map<std::string, ASpell*>::iterator it = this->_spell.find(spell_name);
    if (it != this->_spell.end())
    {
        it->second->launch(target);
    }
}