#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H
#include <string>

int write_new_highscore(const std::string &user_name,
                        int attempts_count);
int read_and_print_highscores();

#endif // HIGH_SCORES_H
