#include <stdio.h>
#include <stdlib.h>
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


void main(){
}
