set( ProjectName di )

project( ${ProjectName} )
cmake_minimum_required( VERSION 3.1.2 )


# Make Visual Studio link against static runtime:

if ( MSVC )
  foreach(flag_var
  		CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
  		CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
  	if(${flag_var} MATCHES "/MD")
  		string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
  	endif(${flag_var} MATCHES "/MD")
  endforeach(flag_var)
endif ( MSVC )


# Multi configuration build setup:

if ( MULTI_CONFIG )
	include( ${CMAKE_BINARY_DIR}/conanbuildinfo_multi.cmake )
else( MULTI_CONFIG )
	include( ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake )
endif( MULTI_CONFIG )

conan_basic_setup( TARGETS )


# Setting targets:

add_executable( ${ProjectName}
  ${CMAKE_SOURCE_DIR}/src/main.cpp
  ${CMAKE_SOURCE_DIR}/src/processor.cpp
  ${CMAKE_SOURCE_DIR}/policies/keyboard_input/keyboard.cpp
  ${CMAKE_SOURCE_DIR}/policies/keyboard_output/keyboard_output.cpp )

target_include_directories( ${ProjectName}
  PRIVATE ${CMAKE_SOURCE_DIR}/include
  PRIVATE ${CMAKE_SOURCE_DIR}/policies/keyboard_input
  PRIVATE ${CMAKE_SOURCE_DIR}/policies/keyboard_output )

target_include_directories( ${ProjectName}
  PRIVATE ${CMAKE_SOURCE_DIR}/submodules/di/include )

target_link_libraries( ${ProjectName} CONAN_PKG::boost )


# Test

add_executable( test_processor
  ${CMAKE_SOURCE_DIR}/test/test_processor.cpp
  ${CMAKE_SOURCE_DIR}/src/processor.cpp
  ${CMAKE_SOURCE_DIR}/test/policies/fixed_string_input/fixed_string.cpp
  ${CMAKE_SOURCE_DIR}/policies/keyboard_output/keyboard_output.cpp )

target_include_directories( test_processor
  PRIVATE ${CMAKE_SOURCE_DIR}/include
  PRIVATE ${CMAKE_SOURCE_DIR}/test/policies/fixed_string_input
  PRIVATE ${CMAKE_SOURCE_DIR}/policies/keyboard_output )


target_include_directories( test_processor
  PRIVATE ${CMAKE_SOURCE_DIR}/submodules/di/include )

target_link_libraries( ${ProjectName} CONAN_PKG::boost )


# Silence some MSVC warnings:

if ( MSVC )
  target_compile_definitions(
  	${ProjectName} PRIVATE
  	_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING
  	_SCL_SECURE_NO_WARNINGS )
endif ( MSVC )


# Force C++17 standard:

set_property ( TARGET ${ProjectName} PROPERTY CXX_STANDARD 17 )
set_property ( TARGET ${ProjectName} PROPERTY CXX_STANDARD_REQUIRED ON )

set_property ( TARGET test_processor PROPERTY CXX_STANDARD 17 )
set_property ( TARGET test_processor PROPERTY CXX_STANDARD_REQUIRED ON )
