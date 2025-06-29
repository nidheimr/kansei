#
#   project
#

cmake_minimum_required(VERSION 3.20)
project(kansei CXX)

set(common_bin_dir ${CMAKE_SOURCE_DIR}/bin/$<0:>)

#
#   executable
#

file(GLOB_RECURSE source_files CONFIGURE_DEPENDS src/*.cpp)
add_executable(kansei ${source_files})

set_target_properties(lux PROPERTIES
    CXX_STANDARD 17
    RUNTIME_OUTPUT_DIRECTORY ${common_bin_dir}
)
