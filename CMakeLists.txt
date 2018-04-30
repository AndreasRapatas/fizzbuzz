cmake_minimum_required(VERSION 3.0)

# Required for YCM to work
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)

project(
	fizzbuzz
	VERSION 1.0.2
	LANGUAGES CXX
)

add_library(
	${PROJECT_NAME}
	./src/fizzbuzz.cpp
)

set_target_properties(
	${PROJECT_NAME}
	PROPERTIES
		PUBLIC_HEADER
			./include/fizzbuzz.h
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

# =======
# Testing
# =======

include(CTest)
if (BUILD_TESTING)

	add_executable(
		test_${PROJECT_NAME}
		./tests/main.cpp
	)

	target_link_libraries(
		test_${PROJECT_NAME}
		PRIVATE
			${PROJECT_NAME}
	)

	add_test(
		NAME test_${PROJECT_NAME}
		COMMAND test_${PROJECT_NAME}
	)

endif()
