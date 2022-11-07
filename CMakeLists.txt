cmake_minimum_required(VERSION 3.5)

project(kulfi LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED OFF)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(PROJECT_NAME kulfi)
include(CMakePrintHelpers)

include_directories(/usr/local/include)
include_directories(src/main/)
include_directories(third_party/)
include_directories(third_party/spdlog/include)
include_directories(third_party/Catch2/single_include/catch2)
include_directories(third_party/PEGTL/include)
include_directories(third_party/magic_enum/include/)

add_subdirectory(third_party/PEGTL)
add_subdirectory(third_party/spdlog)
add_subdirectory(third_party/fmt)
add_subdirectory(third_party/magic_enum)
find_package(spdlog QUIET)
find_package(fmt QUIET)

link_directories(/usr/local/lib/)

file(
        GLOB
        CATCH2_SRC
        third_party/Catch2/single_include/catch2/*.hpp
)

file(
        GLOB
        CATCH2_SRC
        third_party/Catch2/single_include/catch2/*.hpp
)

file(
        GLOB_RECURSE
        PEGTL_SRC
        third_party/PEGTL/include/*.*
)

file(
        GLOB
        MAGIC_ENUMS_SRC
        third_party/magic_enum/*.hpp
)


file(GLOB_RECURSE
        MAIN_SRC
        src/main/utils/*.*
        src/main/*.cpp
        src/main/*.hpp
        )

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    #    LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)
    #    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} dl)
    target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
endif ()

add_executable(
        ${PROJECT_NAME}
        ${CATCH2_SRC}
        ${PEGTL_SRC}
        ${MAGIC_ENUMS_SRC}
        ${MAIN_SRC}
)

target_link_libraries(
        ${PROJECT_NAME}
        spdlog::spdlog
        taocpp::pegtl
        fmt::fmt-header-only
        magic_enum::magic_enum
)
