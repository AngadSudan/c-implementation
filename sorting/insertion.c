#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Generates an array of random integers of given size.
int* generateArray(int size);

// Sorts the given array using Bubble Sort.
void applyInsertionSort(int arr[], int size);

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size);


int* generateArray(int size) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0;i<size;i++) {
        arr[i] = rand();
    }

    return arr;
}

void applyInsertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int key = arr[i];
        while(j>=0 && arr[j]>key){
          arr[j+1] = arr[j];
            j--;
        } 

        arr[j+1] = key;
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
    applyInsertionSort(arr, size);

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
