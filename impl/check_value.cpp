#include <iostream>

int guess_number(const int target_value) {

  int current_value = 0;
  bool not_win = true;
  std::cout << "target_value = " << target_value << std::endl;
  std::cout << "Enter your guess:" << std::endl;

  int attempts_count = 0;

  do {
    std::cin >> current_value;

    if (current_value > target_value) {
      ++attempts_count;
      std::cout << "less than " << current_value << std::endl;
    } else if (current_value < target_value) {
      ++attempts_count;
      std::cout << "greater than " << current_value << std::endl;
    } else {
      ++attempts_count;
      std::cout << "you win! Attempts = " << attempts_count << std::endl;
      not_win = false;
    }

  } while (not_win);

  return attempts_count;
}