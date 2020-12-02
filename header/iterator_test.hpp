#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "power.hpp"
#include "div.hpp"

TEST(IteratorTest, PowBinaryTest){
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);
    Power* temp = new Power(num1, num2);
    Base* dummy = new Add(temp, num2);

    Iterator* it = dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 2);
    EXPECT_EQ(visit->pow_count(), 1);
}

TEST(VisitorTest, VisitorTest1){
    CountVisitor* visitor = new CountVisitor();
    Base* num1 = new Op(8);
    Base* num2 = new Op(4);

    num1->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 1);
    num2->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 2);
}

TEST(VisitorTest, VisitorTest2){
    CountVisitor* visitor = new CountVisitor();
    Base* num1 = new Op(5);
    Base* num2 = new Op(7);

    num1->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 1);
    num2->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 2);

    Base* temp1 = new Sub(num1, num2);
    Base* temp2 = new Div(num1, num2);
    temp1->accept(visitor);
    temp2->accept(visitor);
    EXPECT_EQ(visitor->op_count(),2);
    EXPECT_EQ(visitor->sub_count(),1);
}


#endif
