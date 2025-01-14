cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(PROJECT_NAME "Algebraic")
set(GCD "${CMAKE_CURRENT_SOURCE_DIR}/GCD")
set(FIBO "${CMAKE_CURRENT_SOURCE_DIR}/Fibo")
set(POWER "${CMAKE_CURRENT_SOURCE_DIR}/Power")
set(PRIMES "${CMAKE_CURRENT_SOURCE_DIR}/Primes")
set(DEST_PATH "${CMAKE_CURRENT_BINARY_DIR}/Debug")

project(${PROJECT_NAME})

add_executable(
  ${PROJECT_NAME}
  Fibonacci.hpp
  Fibonacci.cpp
  GCD.hpp
  GCD.cpp
  Power.hpp
  Power.cpp
  Primes.hpp
  Primes.cpp
  Tests.hpp
  Tests.cpp
  main.cpp
)

file(COPY ${GCD} DESTINATION ${DEST_PATH})
file(COPY ${FIBO} DESTINATION ${DEST_PATH})
file(COPY ${POWER} DESTINATION ${DEST_PATH})
file(COPY ${PRIMES} DESTINATION ${DEST_PATH})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
)
