cmake_minimum_required(VERSION 3.16)
project(lua VERSION 5.2.4)

file(GLOB SOURCES "*.c")

# Create the static library
add_library(lua STATIC ${SOURCES})
