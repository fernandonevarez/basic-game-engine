# Build the sandbox app
add_executable(sandbox
        src/main.cpp
)

target_link_libraries(sandbox
        PRIVATE engine
)

target_include_directories(sandbox
        PRIVATE ${CMAKE_SOURCE_DIR}/engine/include
)
