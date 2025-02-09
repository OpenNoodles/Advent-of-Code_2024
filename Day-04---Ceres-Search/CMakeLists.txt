cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "/usr/bin/gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# DEFINE PROJECT NAME BASED ON FOLDER NAME:
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "-" FOLDER_NAME ${FOLDER_NAME})
string(REPLACE "_" "-" FOLDER_NAME ${FOLDER_NAME})
string(SUBSTRING ${FOLDER_NAME} 0 6 FOLDER_NAME)
set(FOLDER_NAME "Aoc-${FOLDER_NAME}")
if("${FOLDER_NAME}" STREQUAL "")
    message(FATAL_ERROR "FATAL_ERROR::${CMAKE_CURRENT_LIST_LINE}: Aoc processed name is empty.")
endif()
message(STATUS "'${FOLDER_NAME}'")

# DEFINE COMPILATION FEATURES:
set(THIS_PROJECT_COMPILE_OPTIONS
    -Wall
    -Werror 
    -Weffc++
    -Wextra
    -pedantic
    -Wconversion 
    -O3
    -Wshadow
    -Wnon-virtual-dtor
    -Wold-style-cast    
    -Woverloaded-virtual 
    -Wzero-as-null-pointer-constant
    -fPIE 
    -fstack-protector-all 
    -fno-rtti
)
set(THIS_PROJECT_COMPILE_FEATURES
    cxx_std_17
)

# EXTERNAL LIBRARIES:
include(FetchContent)
FetchContent_Declare(
  adventkit
  GIT_REPOSITORY https://github.com/OpenNoodles/AdventKit.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(adventkit)

# DEFINE PROJECT:
project(${FOLDER_NAME})
file(GLOB_RECURSE TARGET_SOURCES_PART_ONE "${CMAKE_CURRENT_SOURCE_DIR}/srcP1/*.cpp")
file(GLOB_RECURSE TARGET_SOURCES_PART_TWO "${CMAKE_CURRENT_SOURCE_DIR}/srcP2/*.cpp")

# FIRST HALF SOURCE
set(TARGET_NAME_PART_ONE ${PROJECT_NAME}-P1)
add_library(${TARGET_NAME_PART_ONE} STATIC ${TARGET_SOURCES_PART_ONE})
target_compile_options(${TARGET_NAME_PART_ONE} PRIVATE ${THIS_PROJECT_COMPILE_OPTIONS})
target_compile_features(${TARGET_NAME_PART_ONE} PRIVATE ${THIS_PROJECT_COMPILE_FEATURES})
target_link_libraries(${TARGET_NAME_PART_ONE} PRIVATE AdventKit)

# SECOND HALF SOURCE
set(TARGET_NAME_PART_TWO ${PROJECT_NAME}-P2)
add_library(${TARGET_NAME_PART_TWO} STATIC ${TARGET_SOURCES_PART_TWO})
target_compile_options(${TARGET_NAME_PART_TWO} PRIVATE ${THIS_PROJECT_COMPILE_OPTIONS})
target_compile_features(${TARGET_NAME_PART_TWO} PRIVATE ${THIS_PROJECT_COMPILE_FEATURES})
target_link_libraries(${TARGET_NAME_PART_TWO} PRIVATE AdventKit)

# MAIN
add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE ${THIS_PROJECT_COMPILE_OPTIONS})
target_compile_features(${PROJECT_NAME} PRIVATE ${THIS_PROJECT_COMPILE_FEATURES})
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ${PROJECT_NAME}-P1 
    ${PROJECT_NAME}-P2
    AdventKit
)
