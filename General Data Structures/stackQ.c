#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* prev;
};

typedef struct Node Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> prev = NULL;
	newNode -> data = data;
	return newNode;
}

void insertStack(Node** head, int data){
	if(*head == NULL) *head = createNode(data);
	else{
		Node* newNode = createNode(data);
		newNode -> prev = *head;
		*head = newNode;
	}
}


void deleteStack(Node** head){
	if(*head == NULL) return;
	else if((*head) -> prev == NULL){
		free(*head);
		*head = NULL;
		return;
	}
	else{
		Node* temp = *head;
		*head = (*head) -> prev;
		free(temp);
		return;
	}
}

void displayAll(Node* head){
	printf("Displaying elements, if present, inside stack ... \n");
	while(head != NULL){
		printf("%d ",head -> data);
		head = head -> prev;
	}
}


