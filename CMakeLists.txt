# cmake --version
cmake_minimum_required(VERSION 3.0)

# set the project name
project(md_program)

set(SOURCES
 src/main.cpp
 src/readXYZ.cpp
 src/leapFrog.cpp
 src/readOpt.cpp
 src/readFF.cpp
 src/genVel.cpp
)

#file(GLOB SOURCES "src/*.cpp")

# name of the executable to be built and list of source files to be compiled
add_executable(md_program ${SOURCES})

#add_executable(md_program ../src/main.cpp ../src/other.cpp)
#add_executable(${PROJECT_NAME} main.cpp other.cpp)

target_include_directories(md_program
 PRIVATE
 ${PROJECT_SOURCE_DIR}/include
)
