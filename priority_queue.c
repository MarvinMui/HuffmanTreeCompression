#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "priority_queue.h"


Node* pq_enqueue(Node** a_head, void* a_value, int (*cmp_fn)(const void*, const void*)) {
	Node* new_node = malloc(sizeof(*new_node));
	*new_node = (Node) { .a_value = a_value, .next = *a_head};

	if(*a_head == NULL || cmp_fn(new_node -> a_value, (*a_head) -> a_value) <= 0) {
		*a_head = new_node;

	} else {
		new_node -> next = (*a_head) -> next;
		(*a_head) -> next = new_node;
		Node* curr = *a_head;

		while(new_node -> next != NULL && cmp_fn(new_node -> next -> a_value, new_node -> a_value) <= 0) {
			curr -> next = new_node -> next;
			curr = curr -> next;
			new_node -> next = curr -> next;
			curr -> next = new_node;
		}
	}
	return new_node;  
}


Node* pq_dequeue(Node** a_head) {
	Node* save = *a_head;
	if(*a_head != NULL) {
		*a_head = (*a_head) -> next;
		save -> next = NULL;
	}
	return save;  
}


Node* stack_push(Node** a_top, void* a_value) {
	Node* new_node = malloc(sizeof(*new_node));
	*new_node = (Node) { .a_value = a_value, .next = *a_top };
	*a_top = new_node;
	return new_node;
}


Node* stack_pop(Node** a_top) {
	return pq_dequeue(a_top);
}


void destroy_list(Node** a_head, void (*destroy_value_fn)(void*)) {
	while(*a_head != NULL) {
		Node* death_row = stack_pop(a_head);
		destroy_value_fn(death_row -> a_value);
		free(death_row);
	}
	*a_head = NULL;
}


#define PRIORITY_QUEUE_C_V0
