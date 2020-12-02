//#include "gtest/gtest.h"
//#include "../header/op2_test.hpp"
#include "../header/iterator_test.hpp"
//#include "../header/visitor_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
