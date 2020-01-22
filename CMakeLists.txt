cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_COVERAGE "Build coverage" OFF)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("tools/gate/cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
  SHA1 "9a3594a61227967fb92159339ba326701b287b19"
)


project(lab-04-boost-fs-Frumka)
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

hunter_add_package(Boost COMPONENTS system filesystem)
find_package(Boost CONFIG REQUIRED system filesystem)

add_library(lab-04-boost-fs-Frumka STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/ftp_file.cpp
)
add_executable(tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)

target_include_directories(lab-04-boost-fs-Frumka
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_include_directories(tests 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(tests GTest::main lab-04-boost-fs-Frumka)
target_link_libraries(lab-04-boost-fs-Frumka Boost::system Boost::filesystem)

enable_testing()
add_test(NAME unit_tests COMMAND tests) 

if(BUILD_COVERAGE)
  set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage build." FORCE)
  list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
  find_package(codecov)
  add_coverage(lab-04-boost-fs-Frumka)
  add_coverage(tests)
  list(APPEND LCOV_REMOVE_PATTERNS "'${PROJECT_SOURCE_DIR}/tests/*'")
  coverage_evaluate()
endif()
