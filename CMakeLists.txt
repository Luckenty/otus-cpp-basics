cmake_minimum_required(VERSION 3.5)

project(multithreading)

add_executable(multithreading
        topk_words.cpp
)

set_target_properties(multithreading PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)