
find_package(Catch2 REQUIRED)
find_package(MPI REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wunused-parameter -larmadillo -std=c++17 ")
include_directories(${CATCH2_INCLUDE_PATH})
include_directories(${MPI_INCLUDE_PATH})
include_directories("../src")
include_directories("../inc")

SET(SOURCES testGrid.cpp testInterval.cpp)#test.cpp testField.cpp testGrid.cpp)
add_executable(tests ${SOURCES} ) 

target_link_libraries(tests Catch2::Catch2WithMain Catch2::Catch2 ${MPI_LIBRARIES})