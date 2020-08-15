cmake_minimum_required(VERSION 3.10)

# 项目名称, 版本
project(Tutorial VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 选项: ON, OFF
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# 将配置传入头文件中: 版本, 选项
configure_file(TutorialConfig.h.in TutorialConfig.h)

if(USE_MYMATH)
	# 添加库子目录
	add_subdirectory(MathFunctions)
	# 额外的库
	list(APPEND EXTRA_LIBS MathFunctions)
	# 额外的包含文件
	#list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()	


# 添加执行体
add_executable(Tutorial tutorial.cxx)
# 目标链接库
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})
# 目标包含目录: 生成的版本头文件, 额外库的头文件
target_include_directories(Tutorial PUBLIC 
	"${PROJECT_BINARY_DIR}"
	#${EXTRA_INCLUDES}
	)

# 安装
install(TARGETS Tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)


# 测试
enable_testing()
add_test(NAME Runs COMMAND Tutorial 25)
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
	PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
	)
# 定义函数以添加测试
function(do_test target arg result)
	add_test(NAME Comp${arg} COMMAND ${target} ${arg})
	set_tests_properties(Comp${arg}
		PROPERTIES PASS_REGULAR_EXPRESSION ${result}
		)
endfunction(do_test)
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial -25 "-25 is [-nan|nan|0]")
#do_test(Tutorial 25 "25 is [-nan|nan|0]")

