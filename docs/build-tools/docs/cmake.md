# CMake

- [CMake Reference Documentation](https://cmake.org/documentation/)
- [Effective Modern CMake](https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1)

## The CMakeLists file

- 命令: `command (args...)`
- 变量: `${VAR}`
- 系统环境变量: `$ENV{VAR}`


## QA


# Add the source in project root directory
aux_source_directory(. DIRSRCS)
# Add header file include directories
include_directories(./ ./hello ./world)
# Add block directories
add_subdirectory(hello)
add_subdirectory(world)
# Target
add_executable(helloworld ${DIRSRCS})
target_link_libraries(helloworld hello world)

aux_source_directory(. DIR_HELLO_SRCS)
add_library(hello ${DIR_HELLO_SRCS})


aux_source_directory(. DIR_WORLD_SRCS)
add_library(world ${DIR_WORLD_SRCS})
