#include <stdio.h>
#include <stdlib.h>

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


int main() {
    // 1. Initialize the queue
    Node* front = NULL;
    Node* rear = NULL;

    printf("--- Test 1: Operations on Empty Queue ---\n");
    displayAll(front, rear);
    deleteQueue(&front, &rear);

    printf("\n--- Test 2: Insert First Element ---\n");
    insertQueue(&front, &rear, 10);
    displayAll(front, rear);
    printf("\nFront: %d, Rear: %d\n", front->data, rear->data);

    printf("\n--- Test 3: Insert More Elements ---\n");
    insertQueue(&front, &rear, 20);
    insertQueue(&front, &rear, 30);
    displayAll(front, rear);
    printf("\nFront: %d, Rear: %d\n", front->data, rear->data);

    printf("\n--- Test 4: Delete an Element ---\n");
    deleteQueue(&front, &rear); // Deletes 10
    displayAll(front, rear);
    printf("\nFront: %d, Rear: %d\n", front->data, rear->data);

    printf("\n--- Test 5: Delete to Empty ---\n");
    deleteQueue(&front, &rear); // Deletes 20
    deleteQueue(&front, &rear); // Deletes 30 (last element)
    displayAll(front, rear);

    printf("\n--- Test 6: Underflow After Emptying ---\n");
    deleteQueue(&front, &rear); // Should fail gracefully

    printf("\n--- Test 7: Re-inserting into Empty Queue ---\n");
    insertQueue(&front, &rear, 100);
    insertQueue(&front, &rear, 200);
    displayAll(front, rear);
    printf("\nFront: %d, Rear: %d\n", front->data, rear->data);

    printf("\n--- Test 8: Deleting All Nodes ---\n");
    deleteAll(&front, &rear);
    displayAll(front, rear);

    printf("\n--- Test 9: Inserting After deleteAll ---\n");
    insertQueue(&front, &rear, 500);
    displayAll(front, rear);
    printf("\nFront: %d, Rear: %d\n", front->data, rear->data);

    // Final cleanup
    deleteAll(&front, &rear);
    return 0;
}
		
