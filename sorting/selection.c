#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Generates an array of random integers of given size.
int* generateArray(int size);

// Sorts the given array using Bubble Sort.
void applySelectionSort(int arr[], int size);

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size);


int* generateArray(int size) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0;i<size;i++) {
        arr[i] = rand();
    }

    return arr;
}

void applySelectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
               min = j;
            }
        }
        if(min!=i){
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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
    applySelectionSort(arr, size);

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
