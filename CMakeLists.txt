cmake_minimum_required(VERSION 3.15)
project(BankAcc C)

set(CMAKE_C_STANDARD 99)

add_executable(BankAcc main.c myBank.c myBank.cpp myBank.h)