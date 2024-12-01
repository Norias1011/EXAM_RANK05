#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "SpellBook.hpp"
#include "ATarget.hpp"

class ASpell;

class Warlock
{
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
        void introduce() const;

        void learnSpell(ASpell* new_spell);
        void forgetSpell(std::string spell_name);
        void launchSpell(std::string spell_name, ATarget &target);
    private:
        Warlock();
        Warlock(Warlock const &src);
        Warlock & operator=(Warlock const &src);
        std::string _name;
        std::string _title;
        SpellBook _spellBook;
};

#endif 