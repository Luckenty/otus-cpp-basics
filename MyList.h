#pragma once

#include <cstddef>

constexpr size_t list_init_size = 0;

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
    Node *m_first;
    Node *m_last;
    std::size_t m_size = list_init_size;
};

#include "MyList.inl"