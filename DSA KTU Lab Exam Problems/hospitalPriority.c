#include <stdio.h>
#include <stdlib.h>

struct Patient{
	int priority;
	char* name;
}


struct Node{
	int size;
	int capacity;
	Patient* heapArr;
}

typedef struct Node heapNode;

heapNode* createHeap(capacity){
	heapNode* newHeap = (heapNode*)malloc(sizeof(heapNode));
	newHeap -> size = 0;
	newHeap -> capacity = capacity;
	newHeap -> heapArr = (Patient *)calloc(capacity,sizeof(Patient));
	return newHeap;
}

void insertEntry
