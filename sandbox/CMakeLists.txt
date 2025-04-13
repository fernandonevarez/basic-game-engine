add_executable(sandbox src/main.cpp)

# Link against the engine library
target_link_libraries(sandbox PRIVATE engine)
