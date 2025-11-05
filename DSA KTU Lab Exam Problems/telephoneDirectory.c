#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	long number;
	char* name;
	struct Node* left;
	struct Node* right;
}Node;

Node* createNode(long n,char* name){
	Node* newNode =(Node *)malloc(sizeof(Node));
	newNode -> left = NULL;
	newNode -> right = NULL;
	newNode -> number = n;
	newNode -> name = (char *)calloc(100,sizeof(char));
	strcpy(newNode -> name,name);
	return newNode;
}	

Node* insertEntry(Node* head,long n,char* name){
	if(head == NULL) head = createNode(n,name);
	else{
		if(strcmp(name,head->name) > 0) head -> right = insertEntry(head -> right,n,name);
		else head -> left = insertEntry(head -> left,n,name);
	}
	return head;
}

Node* inOSuccessor(Node *head){
	if(head == NULL) return NULL;
	head = head -> right;
	while(head -> left != NULL) head = head -> left;
	return head;
}



void inOrder(Node *head){
	if(head == NULL) return;
	inOrder(head -> left);
	printf("Name: %s\n ",head -> name);
	printf("Number: %ld\n",head -> number);
	inOrder(head -> right);
} 

void postOrder(Node *head){
	if(head == NULL) return;
	postOrder(head -> left);
	postOrder(head -> right);
	printf("Name: %s\n ",head -> name);
	printf("Number: %ld\n",head -> number);
}

void preOrder(Node* head){
	if(head == NULL) return;
	printf("Name: %s\n ",head -> name);
	printf("Number: %ld\n",head -> number);
	preOrder(head -> left);
	preOrder(head -> right);
}
	

void main(){
	Node* ptr = NULL;
	ptr = insertEntry(ptr,8921188429,"Anjali Raju");
	ptr = insertEntry(ptr,8921177429,"Kiara Adwani");
	ptr = insertEntry(ptr,8921199429,"Aashwin Raju");
	
	Node* test = inOSuccessor(ptr);
	printf("%s ",test -> name);
}
	
