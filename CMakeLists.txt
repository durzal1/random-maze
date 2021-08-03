cmake_minimum_required(VERSION 3.17)
project(random_maze)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp  creationDFS.cpp creationDFS.h constants.h random.h draw.cpp draw.h)
add_executable(random_maze ${SOURCE_FILES})
target_link_libraries(random_maze mingw32 SDL2main SDL2)
