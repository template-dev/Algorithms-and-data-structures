cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "Algorithms_And_Data_Structures")
project(${PROJECT_NAME})

add_subdirectory(
  ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/Sortings/Selection
)

add_subdirectory(
  ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/Lucky_tickets
)
