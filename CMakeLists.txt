cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
	fizzbuzz
	VERSION 1.0.2
	LANGUAGES CXX
)

add_library(
	${PROJECT_NAME}
	./src/fizzbuzz.cpp
)


target_include_directories(
	${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

set_target_properties(
	PROPERTIES
		PUBLIC_HEADER
			./include/fizzbuzz.h
)

add_executable(
	${PROJECT_NAME}_unit_test
	./tests/main.cpp
)

target_link_libraries(
	${PROJECT_NAME}_unit_test
	PRIVATE
		${PROJECT_NAME}
)

include(CTest)
if (BUILD_TESTING)
	add_test(
		NAME ${PROJECT_NAME}_unit_test
		COMMAND ${PROJECT_NAME}_unit_test
	)
endif()
