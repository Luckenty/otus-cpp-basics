#include "MyList.h"

#include "gtest/gtest.h"

TEST(List, CheckZeroSize) {
    MyList<int> list;
    const size_t expectedZeroSize = 0;

    EXPECT_EQ(list.size(), expectedZeroSize);
}

TEST(List, PushBack) {
    MyList<int> list;

    list.push_back(1);

    const size_t expectedSize = 1;

    EXPECT_EQ(list.size(), expectedSize);
}

TEST(List, Index) {
    MyList<int> list;

    list.push_back(5);

    const size_t expected = 5;

    EXPECT_EQ(list[0]->data, expected);
}

TEST(List, InsertAtFirst) {
    MyList<int> list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.insert(15,0);

    const size_t expectedSize = 4;

    EXPECT_EQ(list[0]->data, 15);
    EXPECT_EQ(list[1]->data, 5);
    EXPECT_EQ(list.size(), expectedSize);
}

TEST(List, InsertAtMiddle) {
    MyList<int> list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.insert(15,1);

    const size_t expectedSize = 4;

    EXPECT_EQ(list[0]->data, 5);
    EXPECT_EQ(list[1]->data, 15);
    EXPECT_EQ(list[2]->data, 6);
    EXPECT_EQ(list.size(), expectedSize);
}

TEST(List, InsertAtEnd) {
    MyList<int> list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.insert(15,2);

    const size_t expectedSize = 4;

    EXPECT_EQ(list[2]->data, 15);
    EXPECT_EQ(list[3]->data, 7);
    EXPECT_EQ(list.size(), expectedSize);
}

TEST(List, EraseFromStart) {
    MyList<int> list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.erase(0);

    const size_t expectedSize = 2;

    EXPECT_EQ(list[0]->data, 6);
    EXPECT_EQ(list[1]->data, 7);
    EXPECT_EQ(list.size(), expectedSize);
}

TEST(List, EraseFromMiddle) {
    MyList<int> list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.erase(1);

    const size_t expectedSize = 2;

    EXPECT_EQ(list[0]->data, 5);
    EXPECT_EQ(list[1]->data, 7);
    EXPECT_EQ(list.size(), expectedSize);
}

TEST(List, EraseFromEnd) {
    MyList<int> list;

    list.push_back(5);
    list.push_back(6);
    list.push_back(7);

    list.erase(2);

    const size_t expectedSize = 2;

    EXPECT_EQ(list[0]->data, 5);
    EXPECT_EQ(list[1]->data, 6);
    EXPECT_EQ(list.size(), expectedSize);
}

TEST(List, CheckBigSize) {
    MyList<int> list;

    for(int i=0; i<100; i++) {
        list.push_back(i);
    }

    const size_t expectedSize = 100;

    EXPECT_EQ(list.size(), expectedSize);
}