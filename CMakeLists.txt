cmake_minimum_required(VERSION 3.0)

project(
	fizzbuzz
	VERSION 1.0.2
	LANGUAGES CXX
)

# Definitions {{{

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

# }}}

# Testing {{{

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

# }}}

# Installation {{{

include(CMakePackageConfigHelpers)

set(destination lib/cmake/${PROJECT_NAME})

write_basic_package_version_file(
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
	"${PROJECT_SOURCE_DIR}/cmake/configs/${PROJECT_NAME}Config.cmake.in"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	INSTALL_DESTINATION ${destination}
)

install(
	FILES
		"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
		"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	DESTINATION ${destination}
)

install(
	TARGETS       ${PROJECT_NAME}
	EXPORT        ${PROJECT_NAME}Targets

	LIBRARY       DESTINATION lib                     COMPONENT Runtime
	RUNTIME       DESTINATION bin                     COMPONENT Runtime
	BUNDLE        DESTINATION bin                     COMPONENT Runtime

	ARCHIVE       DESTINATION lib                     COMPONENT Development
	PUBLIC_HEADER DESTINATION include/${PROJECT_NAME} COMPONENT Development
)

install(
	EXPORT      ${PROJECT_NAME}Targets
	FILE        ${PROJECT_NAME}Targets.cmake
	NAMESPACE   ${PROJECT_NAME}::
	DESTINATION ${destination}
)

# }}}
