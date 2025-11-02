#include <stdio.h>
#include <stdlib.h>
struct Node{
	int start;
	int size;
	int end;
	struct Node* next;
};

struct processNode{
	int pid;
	int startAddr;
	int size;
};
typedef struct processNode processNode;



typedef struct Node Node;

Node* createNode(int start, int end){
	int size = end - start;
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> next = NULL;
	newNode -> start = start;
	newNode -> end = end;
	newNode -> size = size;
	return newNode;
}

void addMemoryBlock(Node** front,Node **rear,int start,int end){
	if(*front == NULL && *front == *rear){ 
		*rear = createNode(start,end);
		*front = *rear;
		printf("First block added successfully! \n");
	}
	else{
		Node* newNode = createNode(start,end);
		(*rear) -> next = newNode;
		*rear = (*rear) -> next;
		printf("Operation Successful! \n");
	}
}

int allocateFirstFit(Node** front, Node** rear, processNode* p){
	Node* temp = *front;
	while(temp -> size < p -> size){
		temp = temp -> next;
	}
	if(temp == NULL) return 0;
	else{
		p -> startAddr = temp -> start;
		temp -> start = temp -> start + p->size;
		return 1;
	}
}
processNode* createProcess(int pid, int size){
	processNode* newProcess = (processNode*) malloc(sizeof(processNode));
	newProcess -> pid = pid;
	newProcess -> size = size;
	newProcess -> startAddr = -1;
	return newProcess;
}

void freeMemory(Node** front, Node** rear, int startAddr, int endAddr){
	Node* firstBlock = *front;
	while(firstBlock != NULL && firstBlock -> end != startAddr)	firstBlock = firstBlock -> next;
	Node* secondBlock = *front;
	while(secondBlock != NULL && secondBlock -> start != endAddr) 	secondBlock = secondBlock -> next;
	if(firstBlock != NULL && secondBlock != NULL){
		firstBlock -> end = secondBlock -> end; //coalescing blocks together
		firstBlock -> next = secondBlock -> next;
		free(secondBlock);
		printf("Free Operation success!\n");
	}
	else if(firstBlock == NULL && secondBlock != NULL){ //process was at the beginning
			secondBlock -> start = startAddr;
			printf("Free Operation success!\n");
	}
	else if(secondBlock == NULL && firstBlock != NULL){	//process was at the end
			firstBlock -> end = endAddr;
			printf("Free Operation success!\n");
	}
	else printf("Failed Error!\n\n");
}

int main(){
	int numFree,start,end;
	printf("Enter the number of free memory blocks: ");
	scanf("%d",&numFree);
	Node* front = NULL;
	Node* rear = NULL;
	for(int i = 0; i < numFree; i++){
		printf("Enter the start and end addresses for free block #%d: ",i+1);
		scanf("%d %d",&start,&end);
		addMemoryBlock(&front,&rear,start,end);
	}
	int firstFitCount = 0;
	
	processNode* p7 = createProcess(7,115);
	if(allocateFirstFit(&front,&rear,p7)) firstFitCount++;
	
	processNode* p10 = createProcess(10,650);
	if(allocateFirstFit(&front,&rear,p10)) firstFitCount++;
	
	/*freeMemory(&front,&rear,3150,3500); //free P3
	freeMemory(&front,&rear,1000,1500); //free P1
	freeMemory(&front,&rear,310,400); //free P6
	*/
	
	
		
	//freeMemory(&front,&rear,1850,2000);
	printf("All memory blocks added successfully!\n");
	return 0;
}


