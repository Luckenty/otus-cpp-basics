#pragma once

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
    static constexpr size_t ARRAY_CAPACITY = 5;
    static constexpr size_t ARRAY_INIT_SIZE = 0;

    size_t m_size = ARRAY_INIT_SIZE;
    size_t m_capacity = ARRAY_CAPACITY;
    T *m_data;
};

#include "MyContainer.inl"