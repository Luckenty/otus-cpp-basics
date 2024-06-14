#pragma once

#include <cstddef>

template<class T>
class MyList {
public:
    struct Node {
        Node *next;
        Node *prev;
        T data;

        Node();
    };

    MyList();

    void push_back(T value);

    void insert(T value, int index);

    void erase(int index);

    Node *operator[](int index);

    [[nodiscard]] size_t size() const;

private:
    static constexpr size_t LIST_INIT_SIZE = 0;

    Node *m_first;
    Node *m_last;
    std::size_t m_size = LIST_INIT_SIZE;
};

#include "MyList.inl"