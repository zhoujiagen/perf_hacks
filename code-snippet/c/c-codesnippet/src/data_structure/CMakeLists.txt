
add_executable(test_btree
	btree/test_btree.c
	btree/btree.c)

add_executable(test_link_list
	list/test_link_list.c
	list/link_list.c
	item/item.c)

add_executable(test_number
	number/test_number.c
	number/number.c)

add_executable(test_point
	point/test_point.c
	point/point.c
	number/number.c)

add_executable(test_queue
	queue/test_queue.c
	queue/queue.c
	item/item.c)

add_executable(insertion_array_sort
	sort/test_array_sort.c
	sort/insertion_array_sort.c)

add_executable(selection_array_sort
	sort/test_array_sort.c
	sort/selection_array_sort.c)

add_executable(test_stack
	stack/test_stack.c
	stack/stack.c
	item/item.c)

add_executable(test_more_string
	string/test_more_string.c
	string/more_string.c)
