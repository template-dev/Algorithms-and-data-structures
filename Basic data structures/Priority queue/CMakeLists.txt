cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "PriorityQueue")

project(${PROJECT_NAME})

add_executable(
  ${PROJECT_NAME}
  PriorityQueue.hpp
  PriorityQueue.inl
  main.cpp
)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
