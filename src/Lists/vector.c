//#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


vector* vector_new(){
	vector* new_vector = (vector *) malloc(sizeof(vector));
	
	new_vector -> space = 1;
	new_vector -> count = 0;
	new_vector -> data = (void**)malloc(sizeof(void*));

	return new_vector;
}

void vector_append(vector* vec, void* value){
	if(vec -> count == vec -> space){

		void** new_data = (void**) malloc(sizeof(void*) * (vec -> space) * 2);
		
		for(int i = 0; i < vec -> count; i++){
			new_data[i] = vec -> data[i];
		}

		free(vec -> data);
		vec -> data = new_data;
		vec -> space = 2 * vec -> space;
	}

	vec -> data[vec -> count] = value;
	vec -> count++;
}

int vector_length(vector* vec){
	return vec -> count;
}

void vector_set(vector* vec, int index, void* value){
	vec -> data[index] = value;
}

void* vector_get(vector* vec, int index){
	return vec -> data[index];
}

void vector_remove(vector* vec, int index){
	for(int i = index + 1; i < vec -> count; i++){
		vec -> data[i - 1] = vec -> data[i];
	}
	vec -> count--;

	if(vec -> count <= vec -> space/4 && vec->space != 1){
		void** new_data = (void**) malloc(sizeof(void*) * (vec -> space) / 2);

		for(int i = 0; i < vec -> count; i++){
			new_data[i] = vec -> data[i];
		}

		free(vec -> data);
		vec -> data = new_data;
		vec -> space = vec -> space / 2;

	}
}

void vector_free(vector* vec){
	free(vec -> data);
	free(vec);
}
/*
int main(){
	vector* list = vector_new();
	int arr[10];
	for(int i = 0; i < 10; i++){
		arr[i] = i * i;
	}
	
	for(int i = 0; i < 10; i++){
		vector_append(list, &arr[i]);
	}

	for(int i = 0; i < 10; i++){
		printf("%d\n", * (int*) vector_get(list, i));
	}

	printf("\n");

	printf("%d\n",list -> space);
	printf("%d\n",list -> count);

	vector_remove(list, 0);
	vector_remove(list, 2);

	for(int i = 0; i < list -> count; i++){
		printf("%d\n", * (int*) vector_get(list, i));
	}

	return 0;
}
*/