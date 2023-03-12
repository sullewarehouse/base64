# CMakeList.txt : Top-level CMake project file for base64

cmake_minimum_required (VERSION 3.8)
project ("base64")

ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)

add_executable(base64 "example.cpp" "base64.cpp" "base64.h")

if (WIN32)
	if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
		set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT base64)
		set_target_properties(base64 PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
	endif ()
endif (WIN32)