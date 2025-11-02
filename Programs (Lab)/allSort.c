#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int lb, int mid, int ub){
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int B[ub];
    while(i <= mid && j < ub){
        if(arr[i] > arr[j])
            B[k++] = arr[i++];
        else 
            B[k++] = arr[j++];
        
    }
    while(i <= mid)
        B[k++] = arr[i++];
    while(j < ub)
        B[k++] = arr[j++];
    return B;

}


void mergeSort(int arr[], int lb, int ub){
    int mid = (lb + (ub - lb)) / 2;
    mergeSort(arr,lb,mid);
    mergeSort(arr,mid+1,ub);
    merge(arr,lb,mid,ub);
}


void main(){
    int arr[] = {5,4,1,2,3};
    int n  = 5,temp; 
    for(int i = 1; i < n; i++){
        temp = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp; // assign to next position of j
        }
        
    
    for(int i = 0; i < n ; i++)
        printf("%d ",arr[i]);
    
}
