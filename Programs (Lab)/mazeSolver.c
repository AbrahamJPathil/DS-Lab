#include <stdio.h>
#include <stdlib.h>
struct graph{
	int n;
	int** adjMatrix;
};
typedef struct graph graph;

graph* createGraph(int n){
	graph* newGraph = (graph*) malloc(sizeof(graph));
	newGraph -> n = n;
	newGraph -> adjMatrix = (int **) calloc(n,sizeof(int*));
	for(int i = 0; i < n; i++)
		newGraph -> adjMatrix[i] = (int *) calloc(n,sizeof(int));
	return newGraph;
}

int getNext(int* distance, int* visited,int n){
	int min = 999;
	int index = -1;
	for(int i = 0; i < n; i++){
		if(distance[i] < min && !visited[i]){
			min = distance[i];
			index = i;
		}
	}
	return index;
}

void djikstraOSPF(graph* gp, int target){
	if(gp == NULL) return;
	int* visited = (int*) calloc(gp -> n,sizeof(int));
	int* parent = (int*) calloc(gp -> n,sizeof(int));
	
	int* distance = (int*) calloc(gp -> n,sizeof(int));
	for(int i = 0; i < gp -> n; i++) 	distance[i] = 999;
	int currNode = 0;
	parent[currNode] = -1;
	distance[currNode] = 0;
	for(int j = 0; j < gp -> n; j++){
		for(int i = 0; i < gp -> n; i++){
			if(gp -> adjMatrix[currNode][i] && distance[currNode] + gp-> adjMatrix[currNode][i] < distance[i]){
			distance[i] = distance[currNode] + gp -> adjMatrix[currNode][i];
			parent[i] = currNode;
			}
		}
		visited[currNode] = 1;
		currNode = getNext(distance,visited,gp->n);
		if(currNode == -1) break;
	}
	printf("Shortest path to target %d is",target);
	int temp = parent[target];
	while(temp != -1){
		printf("%d ",temp);
		temp = parent[temp];
	}
	printf("Required cost is: %d",distance[target]);
}

void main(){
	int nodes,target;
	graph* newGraph = NULL;
	printf("Enter the number of nodes in the graph: ");
	scanf("%d",&nodes);
	newGraph = createGraph(nodes);
	for(int i = 0; i < nodes; i++){
		for(int j = 0; j < nodes; j++)	scanf("%d",&newGraph->adjMatrix[i][j]);
	}
	printf("Enter the target node: ");
	scanf("%d",&target);
	djikstraOSPF(newGraph,target);
}
