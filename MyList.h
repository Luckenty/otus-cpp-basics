#ifndef CONTAINERS_MYLIST_H
#define CONTAINERS_MYLIST_H

#include <cstddef>

template<typename T>
class MyList {
public:
    struct Node {
        Node *next;
        Node *prev;
        T data;

        Node() : next(nullptr), prev(nullptr), data(nullptr) {}
    };

    MyList() : m_first(nullptr), m_last(nullptr), m_size(0) {}

    void push_back(T value) {
        Node *new_node = new Node{}; // создание нового узла
        new_node->prev = m_last; // предыдущим элементом станет последний
        new_node->next = nullptr; // следующего элемента пока нет
        new_node->data = value; // сохраняем пользовательские данные
        if (m_first == nullptr) {
            m_first = new_node; // обновляем указатель на первый элемент
            m_last = new_node; // обновляем указатель на последний
        } else {
            m_last = new_node; // обновляем указатель на последний
        }
        m_size += 1; // обновляем размер
    }

    void insert(T value, int index) {
        Node node = this->operator[](index);
        if (node != nullptr) {
            Node nodePrev = node.prev;
            Node nodeNext = node.next;
            Node *new_node = new Node{};
            new_node->prev = nodePrev;
            new_node->next = nodeNext;
            new_node->data = value;
            nodePrev.next = new_node;
            nodeNext.prev = new_node;
            delete[] node;
        }
    }

    Node *operator[](const int index) {
        if (m_first == nullptr) return nullptr;
        Node *pNode = m_first;
        for (int i = 0; i < index; i++) {
            pNode = pNode->next;
            if (!pNode) return nullptr;
        }
        return pNode;
    }

    int size() const {
        return m_size;
    }

private:
    Node *m_first;
    Node *m_last;
    std::size_t m_size;
};

#endif //CONTAINERS_MYLIST_H
