cmake_minimum_required (VERSION 2.6)

project (cplusplus)

# C++11
set (CMAKE_CXX_STANDARD 11)

# 包含目录
include_directories(
	src
)

#add_executable(hello_world src/hello_world.cpp)
# 引入示例
include(example_types.cmake)
include(example_functions.cmake)
include(example_namespaces.cmake)
include(example_classes.cmake)
include(example_templates.cmake)

# 引入Boos
#include(example_boost.cmake)

# 引入数据结构示例
include(example_data_structure.cmake)


