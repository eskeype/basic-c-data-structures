#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct dl_node{
	struct dl_node* prev;
	struct dl_node* next;
	void* data;

}list_node;

typedef struct{
	list_node* head;
	list_node* tail;
	int count;

}linked_list;

/*
Returns a pointer to an initialized empty linked_list
*/
linked_list* linked_list_new();

/*
Appends a new element to the end of 'list'
*/
void linked_list_append(linked_list* list, void* value);

/*
Returns the number of elements contained in 'list'
*/
int linked_list_length(linked_list* list);

/*
Sets the 'index'th element of 'list' to 'value'. Invalid if 'index' is not in [0 ... vector_length(list) - 1]
*/
void linked_list_set(linked_list* list, int index, void* value);

/*
Returns the 'index'th element of 'list'. Invalid if 'index' is not in [0 ... vector_length(list) - 1]
*/
void* linked_list_get(linked_list* list, int index);

/*
Removes the 'index'th element from 'list', updating the indicies of the elements with indices greater than 'index'
Invalid if 'index' is not in [0 ... vector_length(list) - 1]
*/
void linked_list_remove(linked_list* list, int index);

/*
Frees dynamically allocated memory associated with 'list'
*/
void linked_list_free(linked_list* list);



#endif //LINKED_LIST_H