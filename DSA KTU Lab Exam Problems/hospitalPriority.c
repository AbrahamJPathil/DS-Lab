#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Patient{
	int priority;
	char* name;
}Patient;

void swap(Patient* p1,Patient *p2){
	char tempName[100];
	strcpy(tempName,p1 -> name);
	strcpy(p1 -> name,p2 -> name);
	strcpy(p2 -> name,tempName);
	
	int tmpPri;
	tmpPri = p1 -> priority;
	p1 -> priority = p2 -> priority;
	p2 -> priority = tmpPri;
}

typedef struct Node{
	int size;
	int capacity;
	Patient* heapArr;
}heapNode;


heapNode* createHeap(int capacity){
	heapNode* newHeap = (heapNode*)malloc(sizeof(heapNode));
	newHeap -> size = 0;
	newHeap -> capacity = capacity;
	newHeap -> heapArr = (Patient *)calloc(capacity,sizeof(Patient));
	for(int i = 0; i < capacity;i++) newHeap -> heapArr[i].name = (char *)calloc(100,sizeof(char));
	return newHeap;
}

void insertEntry(heapNode* newHeap,int priority,char* name){
	if(newHeap -> size == newHeap -> capacity - 1) return;
	int currIndex = newHeap -> size;
	strcpy(newHeap -> heapArr[currIndex].name,name);
	newHeap -> heapArr[currIndex].priority = priority;
	newHeap -> size++;
	while(currIndex > 0 && newHeap -> heapArr[(currIndex - 1)/2].priority < newHeap -> heapArr[currIndex].priority){
		swap(&newHeap -> heapArr[currIndex],&newHeap -> heapArr[(currIndex-1)/2]);
		currIndex = (currIndex - 1)/2;
	}
}

void heapifyDown(heapNode* newHeap,int index){
	int largest = index;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;
	if(leftChild < newHeap -> size && newHeap -> heapArr[leftChild].priority > newHeap -> heapArr[largest].priority) largest = leftChild;
	else if(rightChild < newHeap -> size && newHeap -> heapArr[rightChild].priority > newHeap -> heapArr[largest].priority) largest = rightChild;
	
	if(largest != index){
		swap(&newHeap -> heapArr[largest],&newHeap -> heapArr[index]);
		heapifyDown(newHeap,largest);
	}
}

void deleteHighest(heapNode* newHeap){
	char patientName[100];
	int patientPriority = newHeap -> heapArr[0].priority;
	strcpy(patientName,newHeap -> heapArr[0].name);
	
	newHeap -> heapArr[0].priority = newHeap -> heapArr[newHeap -> size - 1].priority;
	strcpy(newHeap -> heapArr[0].name,newHeap -> heapArr[newHeap -> size - 1].name);
	newHeap -> size--;
	heapifyDown(newHeap,0);
	printf("Deleted patient details: \n");
	printf("Name: %s   Priority: %d \n",patientName,patientPriority);
}

void main(){
	heapNode* newHeap = createHeap(10);
	insertEntry(newHeap,1,"Anjali Raju");
	
	insertEntry(newHeap,2,"Kiara Adwani");
	insertEntry(newHeap,0,"Mukesh Ambani");
	
	deleteHighest(newHeap);
}
