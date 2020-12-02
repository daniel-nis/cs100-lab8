#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    protected:
	double val;
    public:
	Op() { }
        Op(double value) : Base() { val = value; }
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val); }
	
	Iterator* create_iterator() {
	    NullIterator* ni = new NullIterator(this);
	    return ni;
	}

        Base* get_left() {
            return nullptr;
        }
        Base* get_right() {
            return nullptr;
        }

        void accept(CountVisitor* count) {
            count->visit_op();
        }

};

#endif //__OP_HPP__
