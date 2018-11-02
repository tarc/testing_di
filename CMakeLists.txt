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


# Injected processors

add_library( keyboard_processor
  ${CMAKE_SOURCE_DIR}/src/processor.cpp
  ${CMAKE_SOURCE_DIR}/policies/keyboard_input/keyboard_input.cpp
  ${CMAKE_SOURCE_DIR}/policies/keyboard_output/keyboard_output.cpp )

target_include_directories( keyboard_processor
  PRIVATE ${CMAKE_SOURCE_DIR}/include
  PUBLIC ${CMAKE_SOURCE_DIR}/policies/keyboard_input
  PUBLIC ${CMAKE_SOURCE_DIR}/policies/keyboard_output )


add_library( fixed_string_input_fill_buffer_output_processor
  ${CMAKE_SOURCE_DIR}/src/processor.cpp
  ${CMAKE_SOURCE_DIR}/test/policies/fixed_string_input/fixed_string_input.cpp
  ${CMAKE_SOURCE_DIR}/test/policies/fill_buffer_output/fill_buffer_output.cpp )

target_include_directories( fixed_string_input_fill_buffer_output_processor
  PRIVATE ${CMAKE_SOURCE_DIR}/include
  PUBLIC ${CMAKE_SOURCE_DIR}/test/policies/fixed_string_input
  PUBLIC ${CMAKE_SOURCE_DIR}/test/policies/fill_buffer_output )


# Setting targets:

add_executable( ${ProjectName} ${CMAKE_SOURCE_DIR}/src/main.cpp )

target_include_directories( ${ProjectName}
  PRIVATE ${CMAKE_SOURCE_DIR}/include
  PRIVATE ${CMAKE_SOURCE_DIR}/submodules/di/include )

target_link_libraries( ${ProjectName}
  CONAN_PKG::boost
  keyboard_processor )


# Test

add_executable( test_processor ${CMAKE_SOURCE_DIR}/test/test_processor.cpp )

target_include_directories( test_processor
  PRIVATE ${CMAKE_SOURCE_DIR}/include
  PRIVATE ${CMAKE_SOURCE_DIR}/submodules/di/include )

target_link_libraries( test_processor
  CONAN_PKG::boost
  fixed_string_input_fill_buffer_output_processor )


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

set_property ( TARGET fixed_string_input_fill_buffer_output_processor
  PROPERTY CXX_STANDARD 17 )
set_property ( TARGET fixed_string_input_fill_buffer_output_processor
  PROPERTY CXX_STANDARD_REQUIRED ON )

set_property ( TARGET keyboard_processor PROPERTY CXX_STANDARD 17 )
set_property ( TARGET keyboard_processor PROPERTY CXX_STANDARD_REQUIRED ON )