#ifndef __MODIFY_HPP__
#define __MODIFY_HPP__

#include "base.hpp"

class Modify : public Base {
public:
    Modify(Base* b);
    
    virtual double evaluate() = 0;
    virtual std::string stringify() = 0;

    virtual Base* get_right() = 0;
    virtual Base* get_left() = 0;

    virtual void accept(CountVisitor*) = 0;
protected:
    Base* base;
};

#endif
