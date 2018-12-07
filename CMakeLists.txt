cmake_minimum_required (VERSION 3.8)

project ("WayNetConverter")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
	# /W3 - Level 3 warnings
    # /MP - Multi-threaded compilation
    # /permissive- - enables stricter C++ standards conformance checks
    set(CMAKE_C_FLAGS   "/W4 /MP /permissive-" CACHE STRING "" FORCE)
    # /EHsc - C++-only exception handling semantics
    # /Zc:throwingNew - let codegen assume `operator new` will never return null
    # /Zc:inline - let codegen omit inline functions in object files
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} /EHsc /Zc:throwingNew,inline" CACHE STRING "" FORCE)
endif()


add_subdirectory ("src")
