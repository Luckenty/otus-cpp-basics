
#include <iostream>

#include "MyContainer.h"
#include "MyList.h"

template<typename T>
void print(MyList<T> &container) {
    for (int i = 0; i < container.size(); i++) {
        auto node = container[i];
        std::cout << node->data << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void print(MyContainer<T> &container) {
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

void container_test() {
    // 1. создание объекта контейнера для хранения объектов типа int
    MyContainer<int> container;

    // 2. добавление в контейнер десяти элементов (0, 1 … 9)
    container.push_back(0);
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);
    container.push_back(5);
    container.push_back(6);
    container.push_back(7);
    container.push_back(8);
    container.push_back(9);

    // 3. вывод содержимого контейнера на экран
    print(container);

    // 4. вывод размера контейнера на экран
    std::cout << "size = " << container.size() << std::endl;

    // 5. удаление третьего (по счёту), пятого и седьмого элементов
    container.erase(2);
    container.erase(3);
    container.erase(4);

    // 6. вывод содержимого контейнера на экран
    print(container);

    // 7. добавление элемента 10 в начало контейнера
    container.insert(10, 0);

    // 8. вывод содержимого контейнера на экран
    print(container);

    // 9. добавление элемента 20 в середину контейнера
    container.insert(20, 4);

    // 10. вывод содержимого контейнера на экран
    print(container);

    // 11. добавление элемента 30 в конец контейнера
    container.push_back(30);

    // 12. вывод содержимого контейнера на экран
    print(container);
}

void list_test() {
    // 1. создание объекта контейнера для хранения объектов типа int
    MyList<int> list;

    // 2. добавление в контейнер десяти элементов (0, 1 … 9)
    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);

    // 3. вывод содержимого контейнера на экран
    print(list);

    // 4. вывод размера контейнера на экран
    std::cout << "size = " << list.size() << std::endl;

    // 5. удаление третьего (по счёту), пятого и седьмого элементов
    list.erase(2);
    list.erase(3);
    list.erase(4);

    // 6. вывод содержимого контейнера на экран
    print(list);

    // 7. добавление элемента 10 в начало контейнера
    list.insert(10, 0);

    // 8. вывод содержимого контейнера на экран
    print(list);

    // 9. добавление элемента 20 в середину контейнера
    list.insert(20, 4);

    // 10. вывод содержимого контейнера на экран
    print(list);

    // 11. добавление элемента 30 в конец контейнера
    list.push_back(30);

    // 12. вывод содержимого контейнера на экран
    print(list);
}

int main(int argc, char **argv) {

    container_test();

    list_test();

    return 0;
}