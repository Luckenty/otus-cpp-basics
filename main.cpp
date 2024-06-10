
#include <fstream>
#include <iostream>

#include "MyContainer.h"

int main(int argc, char **argv) {
    MyContainer<int> container;

    container.push_back(100);
    container.push_back(200);
    container.push_back(300);
    container.push_back(400);
    container.push_back(500);
    container.push_back(600);
    container.insert(123, 3);
    std::cout << "size before erase = " << container.size() << std::endl;
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;

    container.erase(2);

    std::cout << "Container after erase:" << std::endl;
    std::cout << "size after erase = " << container.size() << std::endl;
    for (int i = 0; i < container.size(); i++) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;


    return 0;
}
