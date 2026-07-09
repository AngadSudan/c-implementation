#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Generates an array of random integers of given size.
int* generateArray(int size);

// Sorts the given array using Quick Sort.
void applyQuickSort(int arr[], int size);

// helper prototypes
static int partition(int arr[], int low, int high);
static void quickSortRec(int arr[], int low, int high);

// Returns true if the array is sorted, otherwise false.
bool verifySort(int arr[], int size);


int* generateArray(int size) {
    int *arr = malloc(size * sizeof(int));

    for (int i = 0;i<size;i++) {
        arr[i] = rand();
    }

    return arr;
}

static int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
        }
    }
    int tmp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = tmp;
    return i+1;
}

static void quickSortRec(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortRec(arr, low, p - 1);
        quickSortRec(arr, p + 1, high);
    }
}

void applyQuickSort(int arr[], int n){
    if (n <= 1) return;
    quickSortRec(arr, 0, n - 1);
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
    applyQuickSort(arr, size);

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
