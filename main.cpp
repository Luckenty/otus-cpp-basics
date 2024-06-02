
#include <fstream>
#include <iostream>

#include "MyContainer.h"

int main(int argc, char **argv) {
    MyContainer<int> container;

    container.push_back(10);
    container.push_back(20);
    container.push_back(30);
    container.push_back(40);
    container.push_back(50);
    container.push_back(60);
    std::cout << "size = " << container.size() << std::endl;
    std::cout << "value at index 3 is: " << container[3] << std::endl;

    return 0;
}
