#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int lb,int ub){
    int pivot = lb;
    int start = lb, end = ub;
    while(start < end){
        while(arr[start] < arr[pivot]) start++;
        while(arr[end] > arr[pivot]) end--;
        if(start < end) swap(&arr[start],&arr[end]);
    }
    swap(&arr[pivot],&arr[end]);
    return end;
}

void quickSort(int arr[],int lb, int ub){
    if(lb < ub){
        int locationOfPivot = partition(arr,lb,ub);
        quickSort(arr,lb,locationOfPivot-1);
        quickSort(arr,locationOfPivot+1,ub);
    }
}

void main(){
    int test[] = {23,4,33,1,5,9};
    quickSort(test,0,5);
    for(int i = 0; i < 5; i++) printf("%d ",test[i]);
    printf("\n");
}