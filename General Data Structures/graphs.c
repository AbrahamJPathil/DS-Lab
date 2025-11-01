#include <stdio.h>
#include <stdlib.h>
struct graph{
	int n;
	int* adjMatrix;
}

typedef struct graph graph;



graph* createGraph(){
	int n;
	printf("Enter the number of nodes in graph: ");
	scanf("%d",&n);
	
	graph* newGraph = malloc(sizeof(graph));
	newGraph -> n = n;
	newGraph -> adjMatrix = (int *) malloc(sizeof(int * n * n));
	
	printf("Now enter the adjacency matrix for graph: ");
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++)	scanf("%d",&(newGraph -> adjMatrix)[i][j]);
	}
	printf("Data entered successfully\n");
	
	return newGraph;


void main(){
}
