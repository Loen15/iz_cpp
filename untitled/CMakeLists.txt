cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(start)

message("START_INCLUDE_DIRS = ${START_INCLUDE_DIRS}")
message("START_LIBRARIES = ${START_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${START_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${START_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE m)

add_subdirectory(tests)