#
#   project
#

cmake_minimum_required(VERSION 3.20)
project(kansei C)

set(common_bin_dir ${CMAKE_SOURCE_DIR}/bin/$<0:>)

#
#   submodules
#

add_subdirectory(external/lux)

#
#   executable
#

file(GLOB_RECURSE source_files CONFIGURE_DEPENDS src/*.c)
add_executable(kansei ${source_files})

set_target_properties(kansei PROPERTIES
    C_STANDARD 17
    RUNTIME_OUTPUT_DIRECTORY ${common_bin_dir}
)

target_link_libraries(kansei PRIVATE
    lux
)

target_include_directories(kansei PRIVATE
    external/lux/include
)
