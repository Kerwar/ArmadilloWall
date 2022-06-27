
find_package(Catch2 REQUIRED)
find_package(MPI REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wunused-parameter -Wshadow -pedantic -Wsign-compare -Wtype-limits -Wignored-qualifiers -Wempty-body -Wclobbered -Wuninitialized -std=c++17 -larmadillo -Werror")
include_directories(${CATCH2_INCLUDE_PATH})
include_directories(${MPI_INCLUDE_PATH})
include_directories("../src")
include_directories("../inc")

file(GLOB PROGRAM_SOURCES "../src/*.cpp")
SET(SOURCES ${PROGRAM_SOURCES} testParalel.cpp testGrid.cpp testInterval.cpp testRectangle.cpp testDomain.cpp)

add_executable(tests ${SOURCES} ) 

target_link_libraries(tests Catch2::Catch2WithMain Catch2::Catch2 ${MPI_LIBRARIES})