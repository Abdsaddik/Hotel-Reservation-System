
cmake_minimum_required (VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

project(Hotel_Reservation_System)

include_directories(include)

file(GLOB_RECURSE MAIN "main.cpp")

file(GLOB_RECURSE HEADER "include/*.hpp")

file(GLOB_RECURSE SOURCE "src/*.cpp")

#set(EXECUTABLE_OUTPUT_PATH "build")

add_executable (HoteslSys ${MAIN} ${SOURCE} ${HEADER})

source_group("Header include" FILES ${HEADER})
source_group("Source src"     FILES ${SOURCE})

set(CMAKE_SYSTEM_PROGRAM_PATH bin )

