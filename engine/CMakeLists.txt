# Add external dependencies first
add_subdirectory(external/glm)

# GLFW (comes with its own CMakeLists.txt)
add_subdirectory(external/glfw)

# GLAD (we'll define it manually since it's just a C file)
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# Now create the engine library
add_library(engine STATIC
        src/Engine.cpp
        src/Window.cpp
        src/Renderer.cpp
        src/Shader.cpp
        src/Input.cpp
        src/Entity.cpp
)

target_include_directories(engine PUBLIC
        include
        external/glm
        external/glfw/include
        external/glad/include
)

# Link everything the engine needs
target_link_libraries(engine
        PUBLIC
        glm
        glfw
        glad
)