cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "Lucky_tickets")
set(TEST_DATA "${CMAKE_CURRENT_SOURCE_DIR}/TestData")

project(${PROJECT_NAME})

add_executable(
  ${PROJECT_NAME}
  Solution.hpp
  Solution.cpp
  Test.hpp
  Test.cpp
  main.cpp
 )

 file(COPY ${TEST_DATA} DESTINATION ${CMAKE_BINARY_DIR})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
