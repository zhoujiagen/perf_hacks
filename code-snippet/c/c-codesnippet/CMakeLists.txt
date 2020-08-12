cmake_minimum_required (VERSION 2.6)

project (c)

# C99
set (CMAKE_C_STANDARD 99)

# 包含目录
include_directories(
	src
)

# 引入数据结构示例
include(example_data_structure.cmake)

# 引入POSIX示例
include(example_posix.cmake)