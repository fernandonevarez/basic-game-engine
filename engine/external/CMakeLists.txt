cmake_minimum_required(VERSION 3.20)
project(glad_build C)

add_library(glad STATIC
        glad/src/glad.c
)

target_include_directories(glad PUBLIC
        glad/include
)
