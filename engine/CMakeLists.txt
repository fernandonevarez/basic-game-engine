find_package(glfw3 REQUIRED)

add_library(engine
        src/Engine.cpp
        src/Window.cpp
        src/Renderer.cpp
)

target_include_directories(engine
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link GLFW (already here)
target_link_libraries(engine PUBLIC glfw)

# macOS OPENGL
if (APPLE)
    find_library(OpenGL_LIBRARY OpenGL)
    target_link_libraries(engine PUBLIC ${OpenGL_LIBRARY})
endif ()
