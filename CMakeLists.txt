cmake_minimum_required(VERSION 3.28)
project(guess_the_number)

set(BOOST_ROOT "C:/lib/boost_1_85_0")
set(BOOST_INCLUDEDIR "C:/lib/boost_1_85_0/")

include_directories(include)
include_directories(${BOOST_INCLUDEDIR})

link_directories("C:/lib/boost_1_85_0/stage/lib")

add_executable(main	main.cpp check_value.cpp random_value.cpp high_scores.cpp argument.cpp)

target_link_libraries(main PRIVATE C:/lib/boost_1_85_0/stage/lib/libboost_program_options-vc143-mt-gd-x64-1_85.lib)