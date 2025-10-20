#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{
    char* documentName;
    char* trName;
    int numberPages;
    int pagesPrinted;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(char* dname,char* trName,int nPage){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> next = NULL;
    newNode -> documentName = (char *) malloc(sizeof(strlen(dname)+1));
    newNode -> trName = (char *) malloc(sizeof(strlen(trName)+1));;
    newNode -> numberPages = nPage;
    strcpy(newNode -> documentName,dname);
    newNode -> pagesPrinted = 0;
    strcpy(newNode -> trName,trName);
    return newNode;
    
}

Node* insertNode(Node* headptr, char* dname,char* tr, int nPage){
    if(headptr == NULL) return createNode(dname,tr,nPage);
    else{
        Node* newNode = createNode(dname,tr,nPage);
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

int main(){
    int a = 1,ch;
    Node* head = NULL;
    while(a == 1){
        printf("Enter 2 for adding user to the printing spool, 3 to simulate one minute passing \n");
        scanf("%d",&ch);
        if(ch == 2){
            char file[100];
            char tr[100];
            int pg;
            printf("Enter the teacher name, filename, number of pages of file:  ");
            scanf("%s %s %d",tr,file,&pg);
            head = insertNode(head,file,tr,pg);                       
        }
        else if(ch == 3){
            int ppm = 30;
            while(ppm > 0 && head != NULL){
                if((head -> numberPages - head -> pagesPrinted) <= ppm){
                ppm = ppm -(head -> numberPages - head -> pagesPrinted);
                head = deleteNode(head);
                }
                else{
                    head -> pagesPrinted = ppm;
                    ppm = 0;
                }
            }
        }
        

    }   
    return 0;
}