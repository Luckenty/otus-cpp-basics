#include <fstream>
#include <iostream>
#include <string>

const std::string high_scores_filename = "high_scores.txt";

int write_new_highscore(const std::string &user_name,
                        const int attempts_count) {
  std::ofstream out_file{high_scores_filename, std::ios_base::app};
  if (!out_file.is_open()) {
    std::cout << "Failed to open file for write: " << high_scores_filename
              << "!" << std::endl;
    return -1;
  }

  // Append new results to the table:
  out_file << user_name << ' ';
  out_file << attempts_count;
  out_file << std::endl;

  return 0;
}

int read_and_print_highscores() {
  std::ifstream in_file{high_scores_filename};
  if (!in_file.is_open()) {
    std::cout << "Failed to open file for read: " << high_scores_filename << "!"
              << std::endl;
    return -1;
  }

  std::cout << "\nHigh scores table:" << std::endl;

  std::string username;
  int high_score = 0;
  while (true) {
    // Read the username first
    in_file >> username;
    // Read the high score next
    in_file >> high_score;
    // Ignore the end of line symbol
    in_file.ignore();

    if (in_file.fail()) {
      break;
    }

    // Print the information to the screen
    std::cout << username << '\t' << high_score << std::endl;
  }

  return 0;
}