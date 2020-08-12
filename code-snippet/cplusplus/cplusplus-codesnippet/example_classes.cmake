# 对象和类
#add_executable(test_stock 
#	src/classes/object/test_stock.cpp
#	src/classes/object/stock.cpp)

#add_executable(test_stack 
#	src/classes/object/test_stack.cpp
#	src/classes/object/stack.cpp)

# 使用类
## 运算符重载
#add_executable(test_my_time 
#	src/classes/operator/test_my_time.cpp
#	src/classes/operator/my_time.cpp)

#add_executable(test_my_vector 
#	src/classes/operator/test_my_vector.cpp
#	src/classes/operator/my_vector.cpp)

## 类的转换
#add_executable(test_stone_wt 
#	src/classes/conversion/test_stone_wt.cpp
#	src/classes/conversion/stone_wt.cpp)
	
# 类与动态内存分配
#add_executable(test_my_string 
#	src/classes/allocation/test_my_string.cpp
#	src/classes/allocation/my_string.cpp)
#add_executable(test_my_queue 
#	src/classes/allocation/test_my_queue.cpp
#	src/classes/allocation/my_queue.cpp)
		
# 类继承
#add_executable(test_table_tennis 
#	src/classes/inherits/test_table_tennis.cpp
#	src/classes/inherits/table_tennis.cpp)
## is-a
#add_executable(test_brass 
#	src/classes/inherits/test_brass.cpp
#	src/classes/inherits/brass.cpp)
### 继承和动态内存分配
#add_executable(test_dma 
#	src/classes/inherits/dma/test_dma.cpp
#	src/classes/inherits/dma/dma.cpp)	
### 抽象基类
#add_executable(test_acct_abc 
#	src/classes/inherits/abc/test_acct_abc.cpp
#	src/classes/inherits/abc/acct_abc.cpp)

# 代码重用
## has-a
### 包含
#add_executable(test_student 
#	src/classes/has_a/containment/test_student.cpp
#	src/classes/has_a/containment/student.cpp)
### 私有继承, 保护继承
#add_executable(test_student 
#	src/classes/has_a/use_inherit/test_student.cpp
#	src/classes/has_a/use_inherit/student.cpp)

## 多重继承
add_executable(test_worker 
	src/classes/inherits/multi/test_worker.cpp
	src/classes/inherits/multi/worker.cpp)

## 类模板
#add_executable(test_stack_tp 
#	src/classes/templates/test_stack_tp.cpp)