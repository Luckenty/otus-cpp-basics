cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(guess_number
        main.cpp
        impl/check_value.cpp
        impl/check_value.h
        impl/random_value.cpp
        impl/random_value.h
        impl/high_scores.cpp
        impl/high_scores.h
)

set_target_properties(guess_number PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)