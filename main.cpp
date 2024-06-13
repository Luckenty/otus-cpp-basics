
#include <iostream>

#include "MyContainer.h"
#include "MyList.h"

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
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
    // 4. вывод размера контейнера на экран
    std::cout << "size = " << container.size() << std::endl;
    // 5. удаление третьего (по счёту), пятого и седьмого элементов
    container.erase(2);
    container.erase(3);
    container.erase(4);

    // 6. вывод содержимого контейнера на экран
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;

    // 7. добавление элемента 10 в начало контейнера
    container.insert(10, 0);

    // 8. вывод содержимого контейнера на экран
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;

    // 9. добавление элемента 20 в середину контейнера
    container.insert(20, 4);

    // 10. вывод содержимого контейнера на экран
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;

    // 11. добавление элемента 30 в конец контейнера
    container.push_back(30);

    // 12. вывод содержимого контейнера на экран
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

void list_test() {
    // 1. создание объекта контейнера для хранения объектов типа int
    MyList<int> container;
    // 2. добавление в контейнер десяти элементов (0, 1 … 9)

}

int main(int argc, char **argv) {

    container_test();

    list_test();

    return 0;
}
