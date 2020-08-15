cmake_minimum_required (VERSION 2.6)

project (linux-programming-codesnippet)

# C99
set (CMAKE_C_STANDARD 99)

# 基本库
add_subdirectory(src/lib)
list(APPEND EXTRA_LIBS lib)

# 测试
add_subdirectory(test)

# 各子系统
add_subdirectory(src/process)
add_subdirectory(src/memory)
#add_subdirectory(src/io)
