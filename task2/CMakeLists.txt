cmake_minimum_required(VERSION 2.8)
project(task2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(SOURCES B/lib.h B/lib.cpp C/main.h C/main.cpp)
include_directories(${PROJECT_SOURCE_DIR})

find_package(GTest REQUIRED)

if(NOT GTest_FOUND)
  message(SEND_ERROR "Failed to find gtest library")
  return()
else()
  include_directories(${GTEST_INCLUDE_DIRS})
endif()

add_library(index A/index.cpp)

add_executable(C ${SOURCES})

add_custom_target(
  run ALL
  BYPRODUCTS ${PROJECT_SOURCE_DIR}/A/index.h
  COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/index.h
  COMMENT "Generating header file"
)

add_dependencies(C run)
add_subdirectory(B)
target_link_libraries(C mainlib)
target_link_libraries(C index)


add_executable(CTest C/main_test.cpp)
target_link_libraries(CTest mainlib)
target_link_libraries(CTest index)
target_link_libraries(CTest ${GTEST_LIBRARIES} pthread)

enable_testing()
