#include "impl/check_value.h"
#include "impl/high_scores.h"
#include "impl/random_value.h"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {

  const std::string high_scores_filename = "high_scores.txt";

  // Ask about name
  std::cout << "Hi! Enter your name, please:" << std::endl;
  std::string user_name;
  std::cin >> user_name;

  int attempts_count = guess_number(get_random_value());

  write_new_highscore(user_name, attempts_count);

  read_and_print_highscores();

  return 0;
}