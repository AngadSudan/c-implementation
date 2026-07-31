#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[right]);
    return i;
}

int randomizedPartition(int arr[], int left, int right)
{
    int pivotIndex = left + rand() % (right - left + 1);
    swap(&arr[pivotIndex], &arr[right]);
    return partition(arr, left, right);
}

void quickSelect(int arr[], int left, int right, int k)
{
    if (left >= right)
        return;

    int pivot = randomizedPartition(arr, left, right);

    if (pivot == k)
        return;
    else if (pivot > k)
        quickSelect(arr, left, pivot - 1, k);
    else
        quickSelect(arr, pivot + 1, right, k);
}

int main()
{
    srand(time(NULL));

    int arr[] = {9, 4, 7, 1, 3, 6, 2, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 4;

    quickSelect(arr, 0, n - 1, K - 1);

    printf("First %d smallest elements:\n", K);
    for (int i = 0; i < K; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}