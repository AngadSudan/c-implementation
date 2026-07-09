#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Generates an array of random integers of given size.
int* generateArray(int size);

// Sorts the given array using Heap Sort.
void applyHeapSort(int arr[], int size);

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size);


int* generateArray(int size) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0;i<size;i++) {
        arr[i] = rand();
    }

    return arr;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void applyHeapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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
    applyHeapSort(arr, size);

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
