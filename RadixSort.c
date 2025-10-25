#include <stdio.h>
#include <stdlib.h>
int getMax(int arr[],int size){
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void countSort(int arr[],int size, int pos){
    int* freqArr = calloc(10,sizeof(int));
    int reqIndex;
    for(int i = 0; i < size; i++){
        reqIndex = arr[i]/pos % 10;
        freqArr[reqIndex]++;
    }
    for(int i = 1; i < 10; i++) freqArr[i] = freqArr[i] + freqArr[i-1];
    int* sortedArray = calloc(size,sizeof(int));
    for(int i = size-1; i >= 0; i--){
        reqIndex = arr[i]/pos % 10;
        sortedArray[--freqArr[reqIndex]] = arr[i];
    }
    for(int i = 0; i < size; i++) arr[i] = sortedArray[i]; 
}


void radixSort(int arr[],int size){
    int largest = getMax(arr,size);
    int pos = 1;
    while(largest/pos > 0){
        countSort(arr,size,pos);
        pos *= 10;
    }
}

void main(){
    int test[] = {23,4,33,1,5,9};
    radixSort(test,6);
    for(int i = 0; i < 6; i++) printf("%d ",test[i]);
    printf("\n");
}