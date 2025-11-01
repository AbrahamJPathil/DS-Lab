#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
}

typedef struct Node Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> next = NULL;
	newNode -> data = data;
	return newNode;
}


void insertQueue(Node** front, Node** rear,int data){
	if(*front == *rear && *rear == NULL){
		*front = createNode(data);
		*rear = *front;
		return;
	}
	else{
		(*rear) -> next = createNode(data);
		*rear = (*rear) -> next;
		return;
	}
}

void deleteQueue(Node** front, Node** rear){
	if(*front == *rear && *rear == NULL){
		printf("No element exists to delete \n");
		return;
	}
	else if(*front == *rear){		// only one element found case
		free(*front);
		*front = NULL;
		*rear = NULL;
		return;
	}
	else{
		Node* temp = *front;
		*front = (*front) -> next;
		free(temp);
		return;
	}
}


void displayAll(Node* front){
	if(front == rear && rear == NULL){
		printf("No element exists to display \n");
		return;
	}
	else{
		Node* temp = front;
		while(temp -> next != NULL){
			printf("%d -> ",temp -> data);
			temp = temp -> next;
		}
		printf("%d",temp->data);
	}
}

void deleteAll(Node** front,Node** rear){
	if(*front == *rear && *rear == NULL){
		printf("No element exists to delete \n");
		return;
	}
	else{
		Node* temp = *front;
		Node* holder = temp;
		while(temp -> next != NULL){
			temp = temp -> next;
			free(holder);
			holder = temp;
		}
		free(holder);
		printf("Success!");
	}
}



		
