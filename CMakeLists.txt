cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 20)

# hunter module, keep up-to-date
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.24.14.tar.gz"
    SHA1 "00901c19eefc02d24b16705b5f5a2b4f093a73fb"
)

project(base64)
option(BUILD_TESTS "Build tests" ON)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_library(
    ${PROJECT_NAME} 
    INTERFACE
)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(cmake/packaging.cmake)
if(BUILD_TESTS)
    enable_testing()
    add_executable("${PROJECT_NAME}_tests"
        tests/tests.cpp
    )
    target_link_libraries(
      "${PROJECT_NAME}_tests"
      GTest::gtest_main
      ${PROJECT_NAME}
    )
    include(GoogleTest)
    gtest_discover_tests("${PROJECT_NAME}_tests")
endif()
