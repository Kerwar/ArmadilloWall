cmake_minimum_required(VERSION 3.0.0)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wunused-parameter -Wshadow -pedantic -Wsign-compare -Wtype-limits -Wignored-qualifiers -Wempty-body -Wclobbered -Wuninitialized -std=c++17 -larmadillo -Werror")
include_directories(${CATCH2_INCLUDE_PATH})
include_directories(${MPI_INCLUDE_PATH})
include_directories("../src")
include_directories("../inc")

SET(SOURCES ../main.cpp grid.cpp equals.cpp paralel.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${MPI_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
enable_testing()
