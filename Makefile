.PHONY: test
test:
	gcc -g test.c item.c linked_list.c linked_list_test.c stack.c stack_test.c queue.c queue_test.c kmp.c kmp_test.c -o test