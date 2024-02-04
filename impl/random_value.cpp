#include <iostream>

#include <cstdlib>
#include <ctime>

int get_random_value() {

  // use current time as seed for random generator
  std::srand(std::time(nullptr));

  const int random_value = std::rand() % 100;

  return random_value;
}