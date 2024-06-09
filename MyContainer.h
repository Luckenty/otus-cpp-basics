#ifndef MYCONTAINER_H
#define MYCONTAINER_H

template<typename T>
class MyContainer {
public:
    MyContainer() : m_size(0), m_capacity(10), m_data(new T[m_capacity]) {
    }

    MyContainer(int size)
            : m_size(size), m_capacity(size * 2), m_data(new T[m_capacity]) {
    }

    MyContainer(const MyContainer &other)
            : m_size(other.m_size), m_capacity(other.m_capacity),
              m_data(new T[m_capacity]) {
        for (int i = 0; i < m_size; i++)
            m_data[i] = other.m_data[i];
    }

    ~MyContainer() { delete[] m_data; }

    void push_back(const T &val) {
        if (m_size >= m_capacity)
            increase_capacity(m_capacity * 2);
        m_data[m_size++] = val;
    }

    void insert(const T &val, int index) {
        if (index < 0 || index > m_size)
            return;

        if (m_size >= m_capacity)
            increase_capacity(m_capacity * 2);

        for (int i = m_size - 1; i >= index; i--)
            m_data[i + 1] = m_data[i];

        m_data[index] = val;
        m_size++;
    }

    void increase_capacity(int newCapacity) {
        T *newData = new T[newCapacity];
        for (int i = 0; i < m_size; i++)
            newData[i] = m_data[i];

        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }

    int size() const { return m_size; }

    T &operator[](int index) { return m_data[index]; }

private:
    size_t m_size;
    size_t m_capacity;
    T *m_data;
};

#endif //MYCONTAINER_H
