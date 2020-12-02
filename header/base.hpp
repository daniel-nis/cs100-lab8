#ifndef __BASE_HPP__
#define __BASE_HPP__

#include "../iterator.hpp"
#include "../visitor.hpp"
#include <string>

//class Iterator;

class Base {
    protected:
        Base* left;
        Base* right;

    public:
	/* Constructors */
        Base() { };
	
	/* Pure Virtual Functions*/
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;

        virtual Iterator* create_iterator() {};

        virtual Base* get_left() = 0;
        virtual Base* get_right() = 0;

        virtual void accept(CountVisitor*) = 0;
};

#endif //__BASE_HPP__
