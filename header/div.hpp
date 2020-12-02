#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    protected:
        Base* left;
        Base* right;
    public:
        Div(Base* value1, Base* value2) {
            left = value1;
            right = value2;
        }
        virtual double evaluate() { return (left->evaluate() / right->evaluate()); }
        virtual std::string stringify() {
            return left->stringify() + "/" + right->stringify();
        }

	Iterator* create_iterator() {
		BinaryIterator* bi = new BinaryIterator(this);
		return bi;
	}

	Base* get_left() {
		return left;
	}

	Base* get_right() {
		return right;
	}

	void accept(CountVisitor* count) {
		count->visit_div();
	}

};

#endif
