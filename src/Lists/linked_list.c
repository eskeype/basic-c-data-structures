#include <stdlib.h>
#include "linked_list.h"

/*
private method - returns a pointer to the 'index'th node in list
Invalid if 'index' is not in [0 ... linked_list_length(list) - 1]
*/
list_node* get_node(linked_list* list, int index);

/*
Returns a pointer to an initialized empty linked_list
*/
linked_list* linked_list_new(){
	linked_list* list = (linked_list*) malloc(sizeof(linked_list));
	
	list -> count = 0;
	list -> head = (list_node*) malloc(sizeof(list_node));
	list -> tail = (list_node*) malloc(sizeof(list_node));

	list -> head -> next = list -> tail;
	list -> tail -> prev = list -> head;

	return list;
}

/*
Appends a new element to the end of 'list'
*/
void linked_list_append(linked_list* list, void* value){
	list_node* new_node = (list_node*) malloc(sizeof(list_node));

	new_node -> next = list -> tail;
	new_node -> prev = list -> tail -> prev;

	list -> tail -> prev -> next = new_node;
	list -> tail -> prev = new_node;

	list -> count++;
}

/*
Returns the number of elements contained in 'list'
*/
int linked_list_length(linked_list* list){
	return list -> count;
}

/*
Sets the 'index'th element of 'list' to 'value'. Invalid if 'index' is not in [0 ... linked_list_length(list) - 1]
*/
void linked_list_set(linked_list* list, int index, void* value){
	get_node(list, index) -> data = value;
}

/*
Returns the 'index'th element of 'list'. Invalid if 'index' is not in [0 ... linked_list_length(list) - 1]
*/
void* linked_list_get(linked_list* list, int index){
	return get_node(list, index) -> data;
}

/*
Removes the 'index'th element from 'list', updating the indicies of the elements with indices greater than 'index'
Invalid if 'index' is not in [0 ... linked_list_length(list) - 1]
*/
void linked_list_remove(linked_list* list, int index){
	list_node* remove_node = get_node(list, index);
	
	remove_node -> next -> prev = remove_node -> prev;
	remove_node -> prev -> next = remove_node -> next;

	free(remove_node);

	list -> count--;
}

/*
Frees dynamically allocated memory associated with 'list'
*/
void linked_list_free(linked_list* list){
	while(list -> count != 0){
		linked_list_remove(list, 0);
	}

	free(list -> head);
	free(list -> tail);

	free(list);
}

//add a pop method

list_node* get_node(linked_list* list, int index){
	list_node* current = list -> head -> next;
	
	for(int i = 0; i < index; i++){
		current = current -> next;
	}
	return current;
}