#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//begin code for graph
struct graph{
	int n;
	int** adjMatrix;
};

typedef struct graph graph;



graph* createGraph(){
	int n;
	printf("Enter the number of nodes in graph: ");
	scanf("%d",&n);
	
	graph* newGraph = (graph*) malloc(sizeof(graph));
	newGraph -> n = n;
	newGraph -> adjMatrix = (int **) malloc(sizeof(int*)*n); // allocate memory for an array of pointers
	
	for(int i = 0; i < n; i++)
		newGraph -> adjMatrix[i] = (int *) malloc(sizeof(int)*n); // allocate memory for 1D element at each 							pointrr
	
	printf("Now enter the adjacency matrix for graph: ");
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++)	scanf("%d",&(newGraph -> adjMatrix[i][j]));
	}
	printf("Data entered successfully\n");
	
	return newGraph;
}
//end code for graph


//begin code for stack
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


int deleteStack(stackNode** head){
	if(*head == NULL) return 99;
	else{	
		int n = (*head) -> data;
		stackNode* temp = *head;
		*head = (*head) -> prev;
		free(temp);
		return n;
	}
}

//end code for stack


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

int dfs(graph* gp,int startNode,int target,int* visited){
	memset(visited,0,gp->n*sizeof(int));
	stackNode* head = NULL;
	insertStack(&head,startNode);
	while(head != NULL){
		int currNode = deleteStack(&head);
		visited[currNode] = 1;
		if(currNode == target) return currNode;
		for(int i = 0; i < gp -> n; i++){
			if(gp -> adjMatrix[currNode][i] && !visited[i]){
				insertStack(&head,i);
				visited[i] = 1;
			}
		}
	}
	return -1; //node not found
}
		



void main(){
	graph* gp = createGraph();
	Node* dll = NULL;
	for(int i = 0; i < gp -> n; i++) insertNode(&dll,i);
	
	int* visited = (int*) calloc(gp -> n,sizeof(int));
	/*printf("%d \n",dfs(gp,0,2,visited));
	for (int i = 0; i < gp->n; i++)
    visited[i] = 0;

	printf("%d \n",dfs(gp,0,1,visited));
	

	printf("%d \n",dfs(gp,0,7,visited));
	*/
	
	int startNode = 0;
	int connectedCnt = 0;
	int* arr1 = (int *) calloc(gp->n,sizeof(int));
	arr1[0] = startNode;
	while(dll != NULL){
		deleteNode(&dll,startNode);
		int elementCount = 1;
		Node* temp = dll;
		while(temp != NULL){   //here if temp -> next != NULL means the last node is always excluded
			if(dfs(gp,startNode, temp -> data,visited) == temp -> data){
				Node* del = temp;
				arr1[elementCount++] = temp -> data;
				temp = temp -> next;
				deleteNode(&dll,del->data);
			}
			else temp = temp -> next;
		}
		printf("Connected Compoents: ");
		for(int i = 0; i < elementCount; i++) printf("%d ",arr1[i]);
		printf("\t Element Count: %d \n",elementCount);
		memset(arr1,0,gp->n*sizeof(int));
		connectedCnt++;
		if(dll != NULL){
		startNode = dll -> data;
		arr1[0] = startNode;
		}
	}
	printf("Total number of connected components: %d \n",connectedCnt);
}
		
				
