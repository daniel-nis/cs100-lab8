#ifndef __ITERATOR_TEST_HPP__
#define __ITERATOR_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "power.hpp"

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

#endif
