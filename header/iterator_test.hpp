#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "power.hpp"
#include "div.hpp"
#include "mult.hpp"

TEST(GetChild, OpGetChild){
    Base* num1 = new Op(3);

    EXPECT_EQ(num1->get_left(), nullptr);
    EXPECT_EQ(num1->get_right(), nullptr);
}


TEST(GetChild, PowGetChild){
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);
    Power* temp = new Power(num1, num2);

    EXPECT_EQ(temp->get_left(), num1);
    EXPECT_EQ(temp->get_right(), num2);
}


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
    EXPECT_EQ(visit->op_count(), 1);
    EXPECT_EQ(visit->pow_count(), 1);
}

TEST(IteratorTest, AddBinaryTest){
    Base* num1 = new Op(5);
    Base* num2 = new Op(6);
    Add* temp = new Add(num1, num2);
    Base* dummy = new Add(temp, num2);

    Iterator* it = dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 1);
    EXPECT_EQ(visit->add_count(), 1);
}

TEST(IteratorTest, SubBinaryTest){
    Base* num1 = new Op(5);
    Base* num2 = new Op(6);
    Sub* temp = new Sub(num1, num2);
    Base* dummy = new Add(temp, num2);

    Iterator* it = dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 1);
    EXPECT_EQ(visit->sub_count(), 1);
}

TEST(IteratorTest, MultBinaryTest){
    Base* num1 = new Op(5);
    Base* num2 = new Op(6);
    Mult* temp = new Mult(num1, num2);
    Base* dummy = new Add(temp, num2);

    Iterator* it = dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 1);
    EXPECT_EQ(visit->mult_count(), 1);
}

TEST(IteratorTest, DivBinaryTest){
    Base* num1 = new Op(5);
    Base* num2 = new Op(6);
    Div* temp = new Div(num1, num2);
    Base* dummy = new Add(temp, num2);

    Iterator* it = dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 1);
    EXPECT_EQ(visit->div_count(), 1);
}
/*preorder*/
/*
TEST(IteratorTest, PowPreOrderTest){
    Base* num1 = new Op(3);
    Base* num2 = new Op(7);
    Base* num3 = new Op(6);
    Power* temp = new Power(num1, num2, num3);
    Base* dummy = new Add(temp, num2, num3);

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

TEST(IteratorTest, AddPreOrderTest){
    Base* num1 = new Op(5);
    Base* num2 = new Op(6);
    Add* temp = new Add(num1, num2);
    Base* dummy = new Add(temp, num2);

    Iterator* it = dummy->create_iterator();

    CountVisitor* visit = new CountVisitor();
    it->first();
    while(!it->is_done()){
        Base* phase = it->current();
        phase->accept(visit);
        it->next();
    }
    EXPECT_EQ(visit->op_count(), 1);
    EXPECT_EQ(visit->add_count(), 1);
}
*/
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
    EXPECT_EQ(visitor->div_count(),1);
}

TEST(VisitorTest, VisitorTest3){
    CountVisitor* visitor = new CountVisitor();
    Base* num1 = new Op(2);
    Base* num2 = new Op(4);
    Base* num3 = new Op(3);

    num1->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 1);
    num2->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 2);
    num3->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 3);

    Base* temp1 = new Add(num1, num2);
    Base* temp2 = new Mult(num1, num2);
    Base* temp3 = new Power(num2, num3);

    temp1->accept(visitor);
    temp2->accept(visitor);
    temp3->accept(visitor);
    EXPECT_EQ(visitor->op_count(),3);
    EXPECT_EQ(visitor->add_count(),1);
    EXPECT_EQ(visitor->mult_count(),1);
    EXPECT_EQ(visitor->pow_count(),1);
}

TEST(VisitorTest, VisitorTest4){
    CountVisitor* visitor = new CountVisitor();
    Base* num1 = new Op(4);
    Base* num2 = new Op(9);
    Base* num3 = new Op(2);
    Base* num4 = new Op(1);

    num1->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 1);
    num2->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 2);
    num3->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 3);
    num4->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 4);

    Base* temp1 = new Add(num1, num2);
    Base* temp2 = new Mult(num1, num2);
    Base* temp3 = new Sub(num2, num3);
    Base* temp4 = new Div(num1, num4);

    temp1->accept(visitor);
    temp2->accept(visitor);
    temp3->accept(visitor);
    temp4->accept(visitor);
    EXPECT_EQ(visitor->op_count(),4);
    EXPECT_EQ(visitor->add_count(),1);
    EXPECT_EQ(visitor->mult_count(),1);
    EXPECT_EQ(visitor->sub_count(),1);
    EXPECT_EQ(visitor->div_count(),1);
}

TEST(VisitorTest, VisitorTest5){
    CountVisitor* visitor = new CountVisitor();
    Base* num1 = new Op(4);
    Base* num2 = new Op(9);
    Base* num3 = new Op(2);
    Base* num4 = new Op(1);
    Base* num5 = new Op(5);

    num1->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 1);
    num2->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 2);
    num3->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 3);
    num4->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 4);
    num5->accept(visitor);
    EXPECT_EQ(visitor->op_count(), 5);

    Base* temp1 = new Add(num1, num2);
    Base* temp2 = new Mult(num1, num2);
    Base* temp3 = new Sub(num2, num3);
    Base* temp4 = new Div(num1, num4);
    Base* temp5 = new Power(num3, num5);

    temp1->accept(visitor);
    temp2->accept(visitor);
    temp3->accept(visitor);
    temp4->accept(visitor);
    temp5->accept(visitor);
    EXPECT_EQ(visitor->op_count(),5);
    EXPECT_EQ(visitor->add_count(),1);
    EXPECT_EQ(visitor->mult_count(),1);
    EXPECT_EQ(visitor->sub_count(),1);
    EXPECT_EQ(visitor->div_count(),1);
    EXPECT_EQ(visitor->pow_count(),1);
}

#endif
