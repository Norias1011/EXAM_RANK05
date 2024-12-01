#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

SpellBook::SpellBook(SpellBook const &src)
{
    *this = src;
}

SpellBook & SpellBook::operator=(SpellBook const &src)
{
    if (this != &src)
    {
        _spellBook = src._spellBook;
    }
    return *this;
}

void SpellBook::learnSpell(ASpell* new_spell)
{
    if (new_spell)
        this->_spellBook[new_spell->getName()] = new_spell->clone();
}

void SpellBook::forgetSpell(std::string const &spell_name)
{
    std::map<std::string, ASpell*>::iterator it = this->_spellBook.find(spell_name);
    if (it != this->_spellBook.end())
    {
        delete it->second;
        _spellBook.erase(it);
    }
}

ASpell* SpellBook::createSpell(std::string const &new_spell)
{
    ASpell* tmp = NULL;
    std::map<std::string, ASpell*>::iterator it = _spellBook.find(new_spell);
    if (it != _spellBook.end())
    {
        tmp = _spellBook[new_spell];
    }
    return (tmp);
}