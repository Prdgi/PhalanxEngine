# Set target name
set( TARGET_NAME_CORE_TESTS ${CMAKE_PROJECT_NAME}_Core_Tests )

# Add sources for target
file( GLOB_RECURSE SOURCES_LIB_CORE_TESTS LIST_DIRECTORIES true *.hpp *.cpp *.tpp *.ixx )

# Add library target
add_executable( ${TARGET_NAME_CORE_TESTS} ${SOURCES_LIB_CORE_TESTS} )

# Enable all warnings
target_compile_options( ${TARGET_NAME_CORE_TESTS} PRIVATE /W4 /WX)