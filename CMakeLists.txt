cmake_minimum_required(VERSION 3.11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
project (raylib_cpp
    VERSION 5.0.1
    DESCRIPTION "raylib-cpp C++ Object Oriented Wrapper for raylib"
    HOMEPAGE_URL "https://github.com/robloach/raylib-cpp"
    LANGUAGES C CXX
)

# Options
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(RAYLIB_CPP_IS_MAIN TRUE)
else()
    set(RAYLIB_CPP_IS_MAIN FALSE)
endif()
option(BUILD_RAYLIB_CPP_EXAMPLES "Examples" ${RAYLIB_CPP_IS_MAIN})

set(CMAKE_CXX_STANDARD 20)

# Include Directory
add_subdirectory(include)

# Add raylib and raygui as submodules
add_subdirectory(raylib)
add_subdirectory(raygui/projects/CMake)
add_subdirectory(BufferedRaylib)

# Examples
if(BUILD_RAYLIB_CPP_EXAMPLES)
    add_subdirectory(examples)
    set(BUILD_RAYLIB_CPP_STATIC ON)

    # Testing
    include(CTest)
    enable_testing()
    if(BUILD_TESTING)
        set(CTEST_CUSTOM_TESTS_IGNORE
            pkg-config--static
        )
        add_subdirectory(tests)
    endif()
endif()
