cmake_minimum_required(VERSION 3.5)

project(containers)

add_executable(containers
        src/main.cpp
        src/MyContainer.h
        src/MyContainer.inl
        src/MyList.h
        src/MyList.inl
)

add_executable(
        test_list
        test/my_list_tests.cpp
)

add_executable(
        test_container
        test/my_container_tests.cpp
)

set_target_properties(containers PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

add_subdirectory(
        "${CMAKE_CURRENT_SOURCE_DIR}/googletest"
        "googletest"
)

target_include_directories(
        test_list PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_include_directories(
        test_container PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(
        test_list PRIVATE
        gtest gtest_main
)

target_link_libraries(
        test_container PRIVATE
        gtest gtest_main
)
