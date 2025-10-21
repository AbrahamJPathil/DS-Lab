#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    struct Node* left;
    struct Node* right;
    char* word;
};

typedef struct Node Node;

Node* createNode(Node* head,char* word){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> word = (char*) malloc(100);
    strcpy(newNode -> word,word);
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* insertNode(Node* head, char* word){
    if(head == NULL) return createNode(head,word);
    else if(strcmp(head -> word,word) > 0) head -> left = insertNode(head -> left,word);
    else if(strcmp(head->word,word) < 0) head -> right = insertNode(head -> right,word);
    return head;
}

// define function inSuc to find in order successor

Node* inOrderSuccessor(Node* head){
    Node* temp = head -> right;
    while(temp -> left != NULL) temp = temp -> left;
    return temp;
}



Node* deleteNode(Node* head, char* word){
    if(head == NULL) return NULL;
    else if(strcmp(head -> word,word) > 0) head -> left = deleteNode(head -> left,word);
    else if(strcmp(head -> word,word) < 0) head -> right = deleteNode(head -> right,word);
    else{
        // add the code for 3 cases, no children, free directly, one child & two child
        if(head -> left == NULL){
            Node* temp = head -> right;
            free(head -> word); //added newly to prevent memory leaks
            free(head);
            return temp;
        }
        else if(head -> right == NULL){
            Node* temp = head -> left;
            free(head -> word); // added newly to prevent memory leaks
            free(head);
            
            return temp;
        }
        else{
            Node* inOrderSucc = inOrderSuccessor(head);
            strcpy(head->word,inOrderSucc -> word);
            head -> right = deleteNode(head -> right,inOrderSucc -> word);
        }
    }
    return head;
}


void printInOrder(Node* head){
    if(head == NULL) return;
    printInOrder(head -> left);
    printf("%s ",head->word);
    printInOrder(head -> right);
}


void main(){

}