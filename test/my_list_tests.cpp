#include "MyList.h"

#include "gtest/gtest.h"

TEST(List, CheckZeroSize) {
    MyList<int> list;
    const size_t expectedZeroSize = 0;

    EXPECT_EQ(list.size(), expectedZeroSize);
}
