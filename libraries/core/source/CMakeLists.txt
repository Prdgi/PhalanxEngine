# Set target name
set( TARGET_NAME_CORE ${CMAKE_PROJECT_NAME}_Core )

# Add sources for target
file( GLOB_RECURSE SOURCES_LIB_CORE LIST_DIRECTORIES true *.hpp *.cpp *.tpp *.ixx )

# Add library target
add_library( ${TARGET_NAME_CORE} STATIC ${SOURCES_LIB_CORE} )

# Enable all warnings
target_compile_options( ${TARGET_NAME_CORE} PRIVATE /W4 /WX)