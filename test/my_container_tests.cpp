#include "MyContainer.h"

#include <gtest/gtest.h>

TEST(Container, CheckZeroSize) {
    MyContainer<int> container;

    const size_t expectedZeroSize = 0;

    EXPECT_EQ(container.size(), expectedZeroSize);
}

TEST(Container, PushBack) {
    MyContainer<int> container;

    container.push_back(1);

    const size_t expectedSize = 1;

    EXPECT_EQ(container.size(), expectedSize);
}

TEST(Container, Index) {
    MyContainer<int> container;

    container.push_back(5);

    const size_t expected = 5;

    EXPECT_EQ(container[0], expected);
}

TEST(Container, InsertAtFirst) {
    MyContainer<int> container;

    container.push_back(5);
    container.push_back(6);
    container.push_back(7);

    container.insert(15,0);

    const size_t expectedSize = 4;

    EXPECT_EQ(container[0], 15);
    EXPECT_EQ(container[1], 5);
    EXPECT_EQ(container.size(), expectedSize);
}

TEST(Container, InsertAtMiddle) {
    MyContainer<int> container;

    container.push_back(5);
    container.push_back(6);
    container.push_back(7);

    container.insert(15,1);

    const size_t expectedSize = 4;

    EXPECT_EQ(container[0], 5);
    EXPECT_EQ(container[1], 15);
    EXPECT_EQ(container[2], 6);
    EXPECT_EQ(container.size(), expectedSize);
}

TEST(Container, InsertAtEnd) {
    MyContainer<int> container;

    container.push_back(5);
    container.push_back(6);
    container.push_back(7);

    container.insert(15,2);

    const size_t expectedSize = 4;

    EXPECT_EQ(container[2], 15);
    EXPECT_EQ(container[3], 7);
    EXPECT_EQ(container.size(), expectedSize);
}

TEST(Container, EraseFromStart) {
    MyContainer<int> container;

    container.push_back(5);
    container.push_back(6);
    container.push_back(7);

    container.erase(0);

    const size_t expectedSize = 2;

    EXPECT_EQ(container[0], 6);
    EXPECT_EQ(container[1], 7);
    EXPECT_EQ(container.size(), expectedSize);
}

TEST(Container, EraseFromMiddle) {
    MyContainer<int> container;

    container.push_back(5);
    container.push_back(6);
    container.push_back(7);

    container.erase(1);

    const size_t expectedSize = 2;

    EXPECT_EQ(container[0], 5);
    EXPECT_EQ(container[1], 7);
    EXPECT_EQ(container.size(), expectedSize);
}

TEST(Container, EraseFromEnd) {
    MyContainer<int> container;

    container.push_back(5);
    container.push_back(6);
    container.push_back(7);

    container.erase(2);

    const size_t expectedSize = 2;

    EXPECT_EQ(container[0], 5);
    EXPECT_EQ(container[1], 6);
    EXPECT_EQ(container.size(), expectedSize);
}

TEST(Container, CheckBigSize) {
    MyContainer<int> container;

    for(int i=0; i<100; i++) {
        container.push_back(i);
    }

    const size_t expectedSize = 100;

    EXPECT_EQ(container.size(), expectedSize);
}