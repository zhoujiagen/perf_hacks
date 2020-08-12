# 包含目录
include_directories(
	src/data_structure
)

add_executable(test_btree 
	src/data_structure/btree/test_btree.c
	src/data_structure/btree/btree.c)

add_executable(test_link_list 
	src/data_structure/list/test_link_list.c
	src/data_structure/list/link_list.c
	src/data_structure/item/item.c)

add_executable(test_number
	src/data_structure/number/test_number.c
	src/data_structure/number/number.c)	

add_executable(test_point
	src/data_structure/point/test_point.c
	src/data_structure/point/point.c
	src/data_structure/number/number.c)

add_executable(test_queue 
	src/data_structure/queue/test_queue.c
	src/data_structure/queue/queue.c
	src/data_structure/item/item.c)	
	
add_executable(insertion_array_sort 
	src/data_structure/sort/test_array_sort.c
	src/data_structure/sort/insertion_array_sort.c)	

add_executable(selection_array_sort 
	src/data_structure/sort/test_array_sort.c
	src/data_structure/sort/selection_array_sort.c)		
	
add_executable(test_stack 
	src/data_structure/stack/test_stack.c
	src/data_structure/stack/stack.c
	src/data_structure/item/item.c)		
	
add_executable(test_more_string
	src/data_structure/string/test_more_string.c
	src/data_structure/string/more_string.c)	
	