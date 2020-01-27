#include <gtest/gtest.h>
#include "tested_class.h"


TEST (SumTest, Right) {
    TestClass testclass;
    ASSERT_EQ (8, testclass.add(4,4));
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
