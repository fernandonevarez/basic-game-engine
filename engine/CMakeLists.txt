find_package(glfw3 REQUIRED)

find_path(GLM_INCLUDE_DIR glm/glm.hpp)

if (NOT GLM_INCLUDE_DIR)
    message(FATAL_ERROR "GLM not found")
endif ()

add_subdirectory(external)

add_library(engine
        src/Engine.cpp
        src/Window.cpp
        src/Renderer.cpp
        src/Shader.cpp
        src/Input.cpp
        src/Entity.cpp
)

target_include_directories(engine
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
        PUBLIC ${GLM_INCLUDE_DIR}
)

# === macOS-specific OpenGL linking ===
if (APPLE)
    find_library(OpenGL_LIBRARY OpenGL)
    target_link_libraries(engine
            PUBLIC glad
            PUBLIC glfw
            PUBLIC ${OpenGL_LIBRARY}
    )
else ()
    # Fallback for Linux/Windows (if you ever port it later)
    target_link_libraries(engine
            PUBLIC glad
            PUBLIC glfw
    )
endif ()
