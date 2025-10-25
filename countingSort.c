#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[], int size){
    int min = arr[0], max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > max) max = arr[i];
        else if(arr[i] < min) min = arr[i];
    }
    int freqArraySize = max - min + 1;
    int *freqArray = calloc(freqArraySize,sizeof(int));
    for(int i = 0; i < size; i++){
        freqArray[arr[i]-min]++; //offset by min to avoid overflow
    } // for storing the frequency of occurence of each element
    for(int i = 1; i < freqArraySize ; i++){
        freqArray[i] = freqArray[i] + freqArray[i-1];
    } // for updating the array to hold positions

    int *sortedArray = calloc(size,sizeof(int));
    int reqIndex;
    for(int i = size - 1; i >= 0; i--){
        reqIndex = --freqArray[arr[i]];
        sortedArray[reqIndex] = arr[i];
    } // backtrack approach so as to maintain the stability of the array

    for(int i = 0; i < size; i++){
        arr[i] = sortedArray[i];
    }
}

void main(){
    int test[] = {23,4,33,1,5,9};
    countSort(test,6);
    for(int i = 0; i < 6; i++) printf("%d ",test[i]);
    printf("\n");
}