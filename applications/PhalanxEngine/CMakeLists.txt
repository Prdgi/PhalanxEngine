FILE( GLOB SOURCES *.cpp *.hpp *.tpp *.ipp )
add_library( core STATIC ${SOURCES} )
target_include_directories( core PUBLIC ./include )