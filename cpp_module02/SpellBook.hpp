#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include "ASpell.hpp"
#include <map>

class ASpell;

class SpellBook
{
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
    private:
        SpellBook(SpellBook const &src);
        SpellBook & operator=(SpellBook const &src);
        std::map<std::string, ASpell*> _spellBook;
};

#endif