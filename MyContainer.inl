#include <cstdlib>
#include "MyContainer.h"

template<class T>
MyContainer<T>::MyContainer() : m_data(new T[m_capacity]) {}

template<class T>
MyContainer<T>::MyContainer(size_t size)
        : m_size(size), m_capacity(size * 2), m_data(new T[m_capacity]) {}

template<class T>
MyContainer<T>::MyContainer(const MyContainer &other)
        : m_size(other.m_size), m_capacity(other.m_capacity),
          m_data(new T[m_capacity]) {
    for (int i = 0; i < m_size; i++) { m_data[i] = other.m_data[i]; }
}

template<class T>
MyContainer<T>::~MyContainer() { delete[] m_data; }

template<class T>
void MyContainer<T>::push_back(const T &val) {
    if (m_size >= m_capacity) {
        increase_capacity(m_capacity * 2);
    }
    m_data[m_size++] = val;
}

template<class T>
void MyContainer<T>::insert(const T &val, int index) {
    if (index < 0 || index > m_size) {
        return;
    }

    if (m_size >= m_capacity) {
        increase_capacity(m_capacity * 2);
    }

    for (int i = m_size - 1; i >= index; i--) {
        m_data[i + 1] = m_data[i];
    }

    m_data[index] = val;
    m_size++;
}

template<class T>
void MyContainer<T>::erase(int index) {
    if (index < 0 || index > m_size) {
        return;
    }

    for (int i = index; i < m_size; i++) {
        m_data[i] = m_data[i + 1];
    }
    m_size--;
}

template<class T>
void MyContainer<T>::increase_capacity(size_t newCapacity) {
    T *newData = new T[newCapacity];
    for (int i = 0; i < m_size; i++) {
        newData[i] = m_data[i];
    }

    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

template<class T>
[[nodiscard]] size_t MyContainer<T>::size() const {
    return m_size;
}

template<class T>
T &MyContainer<T>::operator[](int index) {
    return m_data[index];
}