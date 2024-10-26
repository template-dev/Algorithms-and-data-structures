cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "Lucky_tickets")
set(TEST_DATA "${CMAKE_CURRENT_SOURCE_DIR}/TestData")

project(${PROJECT_NAME})

add_executable(
  ${PROJECT_NAME}
  LuckyTikets.hpp
  LuckyTikets.cpp
  Test.hpp
  Test.cpp
  main.cpp
 )

file(COPY ${TEST_DATA} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug")

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
