#include "MyList.h"

template<class T>
MyList<T>::MyList() : m_first(nullptr), m_last(nullptr) {}

template<class T>
MyList<T>::Node::Node() : next(nullptr), prev(nullptr), data(0) {}

template<class T>
void MyList<T>::push_back(T value) {
    Node *new_node = new Node{}; // создание нового узла
    if (m_first == nullptr) {
        m_first = new_node; // обновляем указатель на первый элемент
        m_last = new_node; // обновляем указатель на последний
        new_node->data = value; // сохраняем пользовательские данные
    } else if (m_size == 1) {
        m_first->next = new_node;
        new_node->prev = m_last; // предыдущим элементом станет последний
        new_node->next = nullptr; // следующего элемента пока нет
        new_node->data = value; // сохраняем пользовательские данные
        m_last = new_node; // обновляем указатель на последний
    } else {
        new_node->prev = m_last; // предыдущим элементом станет последний
        new_node->next = nullptr; // следующего элемента пока нет
        new_node->data = value; // сохраняем пользовательские данные
        m_last->next = new_node;
        m_last = new_node; // обновляем указатель на последний
    }
    m_size++; // обновляем размер
}

template<class T>
void MyList<T>::insert(T value, int index) {
    Node *node = this->operator[](index);
    if (node != nullptr) {
        Node *new_node = new Node{};
        new_node->data = value;
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        if (nodePrev == nullptr) {
            nodeNext->prev = new_node;
            new_node->next = node;
            m_first = new_node;
        } else if (nodeNext == nullptr) {
            nodePrev->next = new_node;
            new_node->prev = nodePrev;
            m_last = new_node;
        } else {
            nodePrev->next = new_node;
            new_node->prev = nodePrev;
            new_node->next = node;
        }
        m_size++;
    }
}

template<class T>
void MyList<T>::erase(int index) {
    Node *node = this->operator[](index);
    if (node != nullptr) {
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
        delete[] node;
        m_size--;
    }
}

template<class T>
typename MyList<T>::Node *MyList<T>::operator[](const int index) {
    if (m_first == nullptr) return nullptr;
    Node *pNode = m_first;
    for (int i = 0; i < index; i++) {
        pNode = pNode->next;
        if (!pNode) return nullptr;
    }
    return pNode;
}

template<class T>
size_t MyList<T>::size() const {
    return m_size;
}