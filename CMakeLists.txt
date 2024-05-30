cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

project(trie_map)
add_executable(
	trie_map
	src/main.cpp
	src/Trie.h
	src/catch.hpp
	src/UnitTests.cpp
	)
