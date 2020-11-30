#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include "base.hpp"

class Factory {
public:
    Factory();

    virtual Base* parse(char** input, int length) = 0;

};

class Parse : public Factory {
public:
    Parse();

    Base* parse(char** input, int length);
};

#endif
