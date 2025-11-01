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


void freeAll(Node* head){
    if(head == NULL) return;
    freeAll(head -> left);
    freeAll(head -> right);
    free(head -> word);
    free(head);
}

void main(){
    Node* root = NULL;
    
    // --- 1. Insertion ---
    root = insertNode(root, "mango");
    root = insertNode(root, "apple");
    root = insertNode(root, "strawberry");
    root = insertNode(root, "pear");
    root = insertNode(root, "banana");
    root = insertNode(root, "grape");
    root = insertNode(root, "kiwi");

    printf("Original Tree (In-order): ");
    printInOrder(root); // Expected: apple banana grape kiwi mango pear strawberry
    printf("\n\n");

    // --- 2. Deletion Test Cases ---

    // Case 1: Delete a leaf node ("banana")
    printf("Deleting 'banana' (a leaf node)...\n");
    root = deleteNode(root, "banana");
    printf("Tree after deletion: ");
    printInOrder(root); // Expected: apple grape kiwi mango pear strawberry
    printf("\n\n");

    // Case 2: Delete a node with one child ("grape")
    // 'grape' has one right child, 'kiwi'
    printf("Deleting 'grape' (node with one child)...\n");
    root = deleteNode(root, "grape");
    printf("Tree after deletion: ");
    printInOrder(root); // Expected: apple kiwi mango pear strawberry
    printf("\n\n");

    // Case 3: Delete a node with two children ("mango" - the root)
    // The in-order successor of "mango" is "pear"
    printf("Deleting 'mango' (node with two children)...\n");
    root = deleteNode(root, "mango");
    printf("Tree after deletion: ");
    printInOrder(root); // Expected: apple kiwi pear strawberry
    printf("\n\n");
    // --- 3. Cleanup ---
    freeAll(root);
    printf("Tree has been freed.\n");

    
}
