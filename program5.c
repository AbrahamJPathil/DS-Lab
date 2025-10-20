#include <stdio.h>
#include <stdlib.h>
struct Node{
    char* documentName;
    int numberPages;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(char* dname,int nPage){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> next = NULL;
    newNode -> numberPages = nPage;
    newNode -> documentName = dname;
    return newNode;
    
}

Node* insertNode(Node* headptr, char* dname, int nPage){
    if(headptr == NULL) return createNode(dname,nPage);
    else{
        Node* newNode = createNode(dname,nPage);
        Node* temp = headptr;
        while(headptr -> next != NULL) headptr = headptr -> next;
        headptr -> next = newNode;
        return temp;
    }
}

Node* deleteNode(Node* headptr){
    if(headptr == NULL) return NULL;
    else{
        Node* temp = headptr;
        headptr = headptr -> next;
        free(temp);
        return headptr;
    }
}

