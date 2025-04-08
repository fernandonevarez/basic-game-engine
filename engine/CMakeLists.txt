find_package(glfw3 REQUIRED)

add_subdirectory(external)

add_library(engine
        src/Engine.cpp
        src/Window.cpp
        src/Renderer.cpp
        src/Shader.cpp
)

target_include_directories(engine
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
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
