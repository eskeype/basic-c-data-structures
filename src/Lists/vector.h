#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef struct{
	int space;
	int count;
	void** data;
}vector;

/*
Returns a pointer to an initialized empty vector object
*/
vector* vector_new();

/*
Appends a new element to the end of 'vec'
*/
void vector_append(vector* vec, void* value);

/*
Sets the 'index'th element of 'vec' to 'value'. Invalid if 'index' is not in [0 ... vector_length(vec) - 1]
*/
void vector_set(vector* vec, int index, void* value);

/*
Returns the 'index'th element of vec. Invalid if 'index' is not in [0 ... vector_length(vec) - 1]
*/
void* vector_get(vector* vec, int index);

/*
Removes the 'index'th element from 'vec', updating the indicies of the elements with indices greater than 'index'
Invalid if 'index' is not in [0 ... vector_length(vec) - 1]
*/
void vector_remove(vector* vec, int index);

/*
Frees dynamically allocated memory associated with 'vec'
*/
void vector_free(vector* vec);



#endif//VECTOR_H