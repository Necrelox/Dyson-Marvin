cmake_minimum_required(VERSION 3.1)
project(Dyson-Marvin)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -O3 -std=c++17)
add_executable(Dyson-Marvin src/main.cpp src/tools/curlsmtp.cpp src/tools/curlsmtp.h src/tools/ustd_string.h src/tools/SenderMail.cpp src/tools/SenderMail.h src/Daemon.cpp include/Daemon.hpp)
target_link_libraries(Dyson-Marvin curl)
