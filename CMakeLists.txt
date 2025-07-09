cmake_minimum_required(VERSION 4.1 FATAL_ERROR)

project(LearnGl)

add_executable(LearnGl 
	src/main.cpp
	src/Render/Shaders.cpp
	src/Render/Shaders.h)

add_subdirectory(external/glfw)
target_link_libraries(LearnGl glfw)

add_subdirectory(external/glad)
target_link_libraries(LearnGl glad)