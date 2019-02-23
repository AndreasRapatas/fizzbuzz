cmake_minimum_required(VERSION 3.0)

project(
	fizzbuzz
	VERSION 1.0.2
	LANGUAGES CXX
)

# Definitions {{{

set(
	${PROJECT_NAME}_src
	./src/fizzbuzz.cpp
)

set(
	${PROJECT_NAME}_headers
	./include/fizzbuzz.h
)

add_library(
	${PROJECT_NAME}
	SHARED
	${${PROJECT_NAME}_src}
)

# }}}

# Testing {{{

if (BUILD_TESTING)

	add_executable(
		${PROJECT_NAME}_test
		./tests/main.cpp
	)

	target_link_libraries(
		${PROJECT_NAME}_test
		PRIVATE
			${PROJECT_NAME}
	)

	add_test(
		NAME ${PROJECT_NAME}_test
		COMMAND ${PROJECT_NAME}_test
	)

endif()

# }}}

# Installation {{{

set(destination lib/cmake/${PROJECT_NAME})

# Packaging {{{

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

install(
	FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	DESTINATION ${destination}
)

configure_package_config_file(
	"${PROJECT_SOURCE_DIR}/cmake/configs/${PROJECT_NAME}Config.cmake.in"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	INSTALL_DESTINATION ${destination}
)

install(
	FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	DESTINATION ${destination}
)

# }}}

install(
	TARGETS ${PROJECT_NAME}
	EXPORT  ${PROJECT_NAME}Targets
	LIBRARY DESTINATION lib COMPONENT Development
)

install(
	FILES ${${PROJECT_NAME}_headers}
	DESTINATION include
)

install(
	EXPORT      ${PROJECT_NAME}Targets
	FILE        ${PROJECT_NAME}Targets.cmake
	NAMESPACE   ${PROJECT_NAME}::
	DESTINATION ${destination}
)

# }}}
