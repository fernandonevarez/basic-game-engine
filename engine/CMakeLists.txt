find_package(glfw3 REQUIRED)

add_library(engine
        src/Engine.cpp
        src/Window.cpp
)

target_include_directories(engine
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(engine PRIVATE BUILDING_DLL)

target_link_libraries(engine
        PUBLIC glfw
)