cmake_minimum_required(VERSION 3.12)
project(Kol1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(Dependencies/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(COMMON_SOURCES Dependencies/src/funcs.cpp)

add_executable(Main Main/Main.cpp ${COMMON_SOURCES})

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(Tests Tests/Tests.cpp ${COMMON_SOURCES})

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(Tests)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)