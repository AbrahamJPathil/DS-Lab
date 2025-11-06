#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

typedef struct heap{
	int capacity;
	int size;
	int* heapArr;
}heap;

heap* createHeap(int capacity){
	heap* newHeap = (heap*)malloc(sizeof(heap));
	newHeap -> capacity = capacity;
	newHeap -> size = 0;
	newHeap -> heapArr = (int *)malloc(capacity*sizeof(int));
	return newHeap;
}

void insertHeap(heap* newHeap,int data){
	if(newHeap -> size == newHeap -> capacity) printf("Heap full, insertion not possible!");
	else{
		int currIndex = newHeap -> size;
		newHeap -> heapArr[currIndex] = data;
		newHeap -> size++;
		while(currIndex > 0 && newHeap -> heapArr[(currIndex - 1)/2] > newHeap -> heapArr[currIndex]){
			int temp = newHeap -> heapArr[(currIndex - 1)/2];
			newHeap -> heapArr[(currIndex - 1)/2] = newHeap -> heapArr[currIndex];
			newHeap -> heapArr[currIndex] = temp;
			currIndex = (currIndex - 1)/2;
		}
	}
}

void heapifyDown(heap* newHeap,int index){
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	int currIndex = index;
	if(leftChild < newHeap -> size && newHeap -> heapArr[leftChild] < newHeap -> heapArr[currIndex]) currIndex = leftChild;
	else if(rightChild < newHeap -> size && newHeap -> heapArr[rightChild] < newHeap -> heapArr[currIndex]) currIndex = rightChild;
	if(currIndex != index){
		swap(&newHeap->heapArr[index],&newHeap->heapArr[currIndex]); 
		heapifyDown(newHeap,currIndex);
	}
	else if(currIndex == index) return;
}

int deleteSmallest(heap* newHeap){
	int smallest = newHeap -> heapArr[0];
	newHeap -> heapArr[0] = newHeap -> heapArr[--newHeap->size];
	heapifyDown(newHeap,0);
	return smallest;
}


void main(){
	heap* newHeap = createHeap(10);
	insertHeap(newHeap,5);
	insertHeap(newHeap,4);
	insertHeap(newHeap,3);
	insertHeap(newHeap,1);
	insertHeap(newHeap,2);
	printf("Smallest: %d",deleteSmallest(newHeap));
	free(newHeap);
}
	
		
	
