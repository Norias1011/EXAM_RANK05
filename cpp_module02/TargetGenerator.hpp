#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget* new_target);
        void forgetTargetType(std::string const &type);
        ATarget* createTarget(std::string const &new_target);
    private:
        TargetGenerator(TargetGenerator const &src);
        TargetGenerator &operator=(TargetGenerator const &src);
        std::map<std::string, ATarget*> _targetGen;
};

#endif