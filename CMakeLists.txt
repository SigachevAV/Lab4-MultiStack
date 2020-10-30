cmake_minimum_required(VERSION 2.8) 

set(PROJECT_NAME MultiStack) 
project(${PROJECT_NAME}) 

set(Stack Stack) 
set(MultiStack MultiStack) 
set(test test)
set(gtest gtest)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) 
if(NOT CMAKE_BUILD_TYPE) 
  set(CMAKE_BUILD_TYPE Release) 
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Stack ${CMAKE_CURRENT_SOURCE_DIR}/MultiStack) 

add_subdirectory(MultiStack) 
add_subdirectory(Stack)
add_subdirectory(gtest)
add_subdirectory(tester)
