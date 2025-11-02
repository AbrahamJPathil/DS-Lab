#include <stdio.h>
#include <stdlib.h>
struct stackNode{
	int data;
	struct stackNode* prev;
};

typedef struct stackNode stackNode;

stackNode* createstackNode(int data){
	stackNode* newstackNode = (stackNode*) malloc(sizeof(stackNode));
	newstackNode -> prev = NULL;
	newstackNode -> data = data;
	return newstackNode;
}

void insertStack(stackNode** head, int data){
		stackNode* newstackNode = createstackNode(data);
		newstackNode -> prev = *head;
		*head = newstackNode;
}


void deleteStack(stackNode** head){
	if(*head == NULL) return;
	else{
		stackNode* temp = *head;
		*head = (*head) -> prev;
		free(temp);
		return;
	}
}

void displayAll(stackNode* head){
	printf("Displaying elements, if present, inside stack ... \n");
	while(head != NULL){
		printf("%d ",head -> data);
		head = head -> prev;
	}
}

	
