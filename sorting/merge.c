#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Generates an array of random integers of given size.
int* generateArray(int size);

// Sorts the given array using Bubble Sort.
void applyMergeSort(int arr[], int start, int end);

// Helper function for sorting
void mergeHelper(int arr[], int start, int end, int mid);

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size);


int* generateArray(int size) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0;i<size;i++) {
        arr[i] = rand();
    }

    return arr;
}

void applyMergeSort(int arr[], int start, int end){
    if(start>=end) return;
    int mid = start + (end-start)/2;

    applyMergeSort(arr,start,mid);
    applyMergeSort(arr,mid+1,end);
    mergeHelper(arr,start,mid,end);
}

void mergeHelper(int arr[], int start, int mid, int end){
    int temp[end-start+1];

    int i = start;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i];
            i++;
        }else{
            temp[k++] = arr[j];
            j++;
        }
    }

    while(i<=mid){
        temp[k++] = arr[i];
        i++;
    }

    while(j<=end){
        temp[k++] = arr[j];
        j++;
    }
    k=0;
    for(int i = start;i<=end;i++){
        arr[i] = temp[k++];
    }
}

bool verifySort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]) return false;
    }

    return true;
}
int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate random array
    int *arr = generateArray(size);

    // Start timer
    clock_t start = clock();

    // Apply sorting algorithm
    applyMergeSort(arr, 0,size-1);

    // Stop timer
    clock_t end = clock();

    // Calculate execution time
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Verify correctness
    if (verifySort(arr, size)) {
        printf("Array is sorted successfully.\n");
    } else {
        printf("Sorting failed!\n");
    }

    printf("Execution Time: %.6f seconds\n", executionTime);
    printf("Execution Time: %.3f milliseconds\n", executionTime * 1000);

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
