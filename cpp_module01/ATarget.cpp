#include "ATarget.hpp"

ATarget::ATarget(std::string type): _type(type)
{

} 

ATarget::~ATarget()
{

}

ATarget::ATarget(ATarget const &src)
{
    *this = src;
}

ATarget & ATarget::operator=(ATarget const &src)
{
    if (this != &src)
    {
        _type = src._type;
    }
    return *this;
}

std::string const & ATarget::getType() const
{
    return (_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}