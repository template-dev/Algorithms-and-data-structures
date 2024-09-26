cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "Lucky_tickets")
#set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
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

if(CMAKE_CONFIGURATION_TYPES STREQUAL "Debug")
 message(STATUS "Debug version")
 file(COPY ${TEST_DATA} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Debug")
elseif(CMAKE_CONFIGURATION_TYPES STREQUAL "Release")
 message(STATUS "Release version")
 file(COPY ${TEST_DATA} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Release")
endif()

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
