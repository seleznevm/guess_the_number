cmake_minimum_required(VERSION 3.5)

project(guess_the_number)

include_directories(include)

add_executable(main	main.cpp check_value.cpp random_value.cpp high_scores.cpp argument.cpp)

set_target_properties(main PROPERTIES
CXX_STANDARD 17
CXX_STANDARD_REQUIRED ON
)