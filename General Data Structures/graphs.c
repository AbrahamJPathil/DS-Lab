#include <stdio.h>
#include <stdlib.h>
// adding code for the stack
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


// adding code for queue
struct Node{
	int data;
	struct Node* next;
};

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


void displayAll(Node* front,Node* rear){
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
		*front = NULL;
		*rear = NULL;
		printf("Success!");
	}
}




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
void bfs(graph* gp,int startNode){
	if(gp == NULL) return;
	else if(gp -> adjMatrix == NULL) return;
	Node* front = NULL;
	Node* rear = NULL;
	int size = gp -> n;
	int* visited = calloc(size,sizeof(int)); //initialisation of an array
	int currNode = startNode;
	visited[currNode] = 1;
	insertQueue(&front,&rear,currNode);
	while(front != NULL && rear != NULL){
		for(int i = 0; i < gp->n ; i++){
			if(gp->adjMatrix[currNode][i] && visited[i] != 1){
				insertQueue(&front,&rear,i);
				visited[i] = 1;
			
			}
		}
		deleteQueue(&front,&rear);
		printf("%d ",currNode); // we should print a node in BFS only after exploration completed
		if(front != NULL) currNode = front -> data;
	}
	printf("BFS Traversal Completed");
}

void dfs(graph* gp,int startNode){
	int* visited = (int *)calloc(gp -> n, sizeof(int));
	stackNode* top = NULL;
	insertStack(&top,startNode);
	int currNode;
	visited[startNode] = 1;
	while(top != NULL){
		// start iteration with poping element off
		currNode = top -> data;
		deleteStack(&top);
		printf("%d ",currNode);
		for(int i = (gp -> n) - 1; i >= 0; i--){
			if(gp -> adjMatrix[currNode][i] && visited[i] != 1){
				insertStack(&top,i);
				visited[i] = 1;
			}
		
		}
	}
	printf("DFS traversal successful");
	free(visited);
}	
			
	


int main() {
    // 1. Create the graph
    graph* myGraph = createGraph();
    
    // 2. Ask user for the starting node
    int startNode;
    printf("\nEnter the node to start BFS from (0 to %d): ", myGraph->n - 1);
    scanf("%d", &startNode);

    // 3. Validate input and run YOUR BFS function
    if (startNode >= 0 && startNode < myGraph->n) {
        printf("\n--- Running Your BFS Traversal ---\n");
        dfs(myGraph, startNode);
        printf("\n----------------------------------\n");
    } else {
        printf("Invalid start node. Must be between 0 and %d.\n", myGraph->n - 1);
    }
   return 0;
}
