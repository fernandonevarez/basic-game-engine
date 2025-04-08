add_library(engine
        src/Engine.cpp
        include/engine.h
)

target_include_directories(engine
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(engine PRIVATE BUILDING_DLL)
