#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
    public:
        Warlock(std::string name, std::string title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;
        void setTitle(std::string const &title);
        void introduce() const;
    private:
        Warlock();
        Warlock(Warlock const &src);
        Warlock & operator=(Warlock const &src);
        std::string _name;
        std::string _title;
};

#endif 