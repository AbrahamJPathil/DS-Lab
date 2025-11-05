#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node* createNode(int data){
	Node* newNode = (Node *) malloc(sizeof(Node));
	if(newNode == NULL) exit(1);
	newNode -> prev = NULL;
	newNode -> next = NULL;
	newNode -> data = data;
	return newNode;
}


void insertNode(Node** head,int data){
	if(*head == NULL){
		*head = createNode(data);
		return;
	}
	else{
		Node* temp = createNode(data);
		Node* traverse = *head;
		while(traverse -> next != NULL) traverse = traverse -> next;
		traverse -> next = temp;
		temp -> prev = traverse;
		return;
	}
}

void deleteNode(Node** head, int data){
	if(*head == NULL){ //no element found
		printf("Deletion not possible on empty list");
		return;
	}
	else{
		Node* temp = *head;
		while(temp != NULL && temp -> data != data) temp = temp -> next;
		if(temp == NULL) printf("Data not found");  //required element not found
		else{
			if(temp->prev == NULL && temp -> next == NULL){ //only element of dll deleted
				free(temp);
				*head = NULL;
				return;
			}
			else if(temp -> next == NULL){  //last element of dll deletion
				Node* prev = temp -> prev;
				prev -> next = NULL;
				free(temp);
				return;
			}
			else if(temp -> prev == NULL){ //first element of dll deletion
				Node* next = temp -> next;
				next -> prev = NULL;
				*head = next;
				free(temp);
				return;
			}
			else{
				Node* prev = temp -> prev;
				Node* next = temp -> next;
				prev -> next = next;
				next -> prev = prev;
				free(temp);
				return;
			}
		}
	}
}			

void displayAll(Node* head){
	if(head == NULL) printf("Empty DLL");
	else{
		printf("Elements are: ");
		while(head != NULL){
			printf("%d ",head -> data);
			head = head -> next;
		}
	}
}



