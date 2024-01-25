cmake_minimum_required(VERSION 3.15)
project(pathetic-engine)

set (CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR src)
set(INCLUDE_DIR public)

file(
    COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets/
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/assets/
)

include_directories(${INCLUDE_DIR})
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

find_package(SFML COMPONENTS window graphics system)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
