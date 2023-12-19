# CMake Version
cmake_minimum_required( VERSION 3.27 )

# CXX Standard
set( CMAKE_CXX_STANDARD 20)

# Project Configuration
project(
	"PhalanxEngine"
	DESCRIPTION ""
	VERSION 0.0.0.0
	LANGUAGES CXX
)

# Sub-Projects
add_subdirectory(libraries)
#add_subdirectory(applications)