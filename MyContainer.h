#ifndef MYCONTAINER_H
#define MYCONTAINER_H

template <typename T>
class MyContainer {
public:
    void push_back(T value);
    void insert(int index, T value);
    void erase(int index);
    int size();

    T operator[](int index);

private:
    int m_size;
    T m_region;
};

#endif //MYCONTAINER_H
