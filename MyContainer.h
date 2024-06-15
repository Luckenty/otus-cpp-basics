#pragma once

constexpr size_t array_capacity = 5;
constexpr size_t array_init_capacity = 0;

template<class T>
class MyContainer {
public:
    MyContainer();

    MyContainer(size_t size);

    MyContainer(const MyContainer &other);

    ~MyContainer();

    void push_back(const T &val);

    void insert(const T &val, int index);

    void erase(int index);

    void increase_capacity(size_t newCapacity);

    [[nodiscard]] size_t size() const;

    T &operator[](int index);

private:
    size_t m_size = array_init_capacity;
    size_t m_capacity = array_capacity;
    T *m_data;
};

#include "MyContainer.inl"