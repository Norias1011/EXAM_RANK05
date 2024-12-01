#include "Warlock.hpp" 

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
    std::cout << this->getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->getName() << ": My job here is done!" << std::endl;
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
