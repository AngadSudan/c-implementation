#include <stdio.h>
#include <stdlib.h>

int countInversion(int arr[], int n);
int inversion(int arr[], int start, int end);
int inversionHelper(int arr[], int start, int mid, int end);

int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int inversion = countInversion(arr, n);
    printf("%d\n", inversion);
    return 0;
}

int countInversion(int arr[], int n)
{
    return inversion(arr, 0, n - 1);
}

int inversion(int arr[], int start, int end)
{
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    int count = 0;

    count += inversion(arr, start, mid);
    count += inversion(arr, mid + 1, end);
    count += inversionHelper(arr, start, mid, end);

    return count;
}

int inversionHelper(int arr[], int start, int mid, int end)
{
    int helper[end - start + 1];
    int k = 0;
    int ptr1 = start;
    int ptr2 = mid + 1;
    int count = 0;
    while (ptr1 <= mid && ptr2 <= end)
    {
        if (arr[ptr1] <= arr[ptr2])
        {
            helper[k++] = arr[ptr1++];
        }
        else
        {
            helper[k++] = arr[ptr2++];
            count += mid - ptr1 + 1;
        }
    }

    while (ptr1 <= mid)
    {
        helper[k++] = arr[ptr1++];
    }

    while (ptr2 <= end)
    {
        helper[k++] = arr[ptr2++];
    }
    k = 0;
    for (int i = start; i <= end; i++)
    {
        arr[i] = helper[k++];
    }
    return count;
}