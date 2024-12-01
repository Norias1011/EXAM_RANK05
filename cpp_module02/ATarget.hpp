#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    public:
        ATarget(std::string type);
        virtual ~ATarget();
        ATarget &operator=(ATarget const &src);
        ATarget(ATarget const &src);
        std::string const &getType() const;
        virtual ATarget *clone() const = 0;

        void getHitBySpell(ASpell const &spell) const;
    private:
        std::string _type;
};

#endif