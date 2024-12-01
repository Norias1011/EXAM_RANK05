#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{

}
TargetGenerator::TargetGenerator(TargetGenerator const &src)
{
    *this = src;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const &src)
{
    if (this != &src)
    {
        _targetGen = src._targetGen;
    }
    return *this;
}

void TargetGenerator::learnTargetType(ATarget* new_target)
{
    if (new_target)
        this->_targetGen[new_target->getType()] = new_target;
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
    std::map<std::string, ATarget*>::iterator it = this->_targetGen.find(type);
    if (it != this->_targetGen.end())
    {
        delete it->second;
        _targetGen.erase(it);
    }
}

ATarget* TargetGenerator::createTarget(std::string const &new_target)
{
    ATarget* tmp = NULL;
    std::map<std::string, ATarget*>::iterator it = _targetGen.find(new_target);
    if (it != _targetGen.end())
    {
        tmp = _targetGen[new_target];
    }
    return (tmp);
}