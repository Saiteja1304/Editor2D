cmake_minimum_required(VERSION 3.0.0)
project(Editor2D VERSION 0.1.0)

#PLATFORM CHEKCS
if(UNIX)
message("[PLATFORM] [UNIX]")
add_compile_definitions(_UNIX_)
endif(UNIX)
if(WIN32)
message("[PLATFORM] [WINDOWS]")
add_compile_definitions(_WIN_)
endif(WIN32)

# Get all source files
file(GLOB_RECURSE SRC src/*.cpp src/*.c)
#IMGUI
file(GLOB IMGUI libUI/*.h libUI/*.cpp)
# SRC
file(GLOB_RECURSE SRC src/*.cpp src/*.c)

add_subdirectory(glfw)
add_subdirectory(Core)

add_executable(Editor2D main.cpp ${SRC} ${IMGUI})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
#BUILD TYPES
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
message("[BUILD] [DEBUG]")
add_compile_definitions(_DEBUG_)
endif(CMAKE_BUILD_TYPE STREQUAL "Debug")

target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw Core)