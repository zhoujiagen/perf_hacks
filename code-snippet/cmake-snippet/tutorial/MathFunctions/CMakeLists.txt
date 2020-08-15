
# 添加库
add_library(MathFunctions mysqrt.cxx)

# 库的包含文件: 使用方的需求(usage requirement)
target_include_directories(MathFunctions
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
	)
	
# 安装
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)