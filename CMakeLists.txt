cmake_minimum_required(VERSION 3.5)
project(guess_the_number)

include_directories(include)

add_executable(main	main.cpp check_value.cpp random_value.cpp high_scores.cpp)