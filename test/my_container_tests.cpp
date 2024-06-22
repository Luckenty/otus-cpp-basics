#include "MyContainer.h"

#include <gtest/gtest.h>

TEST(Container, CheckZeroSize) {
    MyContainer<int> container;

    const size_t expectedZeroSize = 0;

    EXPECT_EQ(container.size(), expectedZeroSize);
}