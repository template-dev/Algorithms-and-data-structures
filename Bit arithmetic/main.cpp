cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "BitArithmetic")

project(${PROJECT_NAME})

add_executable(
  ${PROJECT_NAME}
  main.cpp
)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
