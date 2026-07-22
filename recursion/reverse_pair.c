#include <stdio.h>
#include <stdlib.h>

int countReversePairs(int arr[], int n);
int reversePairs(int arr[], int start, int end);
int pairs(int arr[], int start, int mid, int end);

int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int pairs = countReversePairs(arr, n);
    printf("%d\n", pairs);
    return 0;
}

int countReversePairs(int arr[], int n)
{
    return reversePairs(arr, 0, n - 1);
}

int reversePairs(int arr[], int start, int end)
{
    if (start >= end)
        return 0;

    int mid = start + (end - start) / 2;
    int count = 0;
    count += reversePairs(arr, start, mid);
    count += reversePairs(arr, mid + 1, end);
    count += pairs(arr, start, mid, end);

    return count;
}

int pairs(int arr[], int start, int mid, int end)
{
    int count = 0;
    int j = mid + 1;
    for (int i = start; i <= mid; i++)
    {
        while (j <= end && arr[i] > 2 * arr[j])
            j++;
        count += j - (mid + 1);
    }

    int helper[end - start + 1];
    int k = 0;
    int ptr1 = start;
    int ptr2 = mid + 1;

    while (ptr1 <= mid && ptr2 <= end)
    {
        if (arr[ptr1] <= arr[ptr2])
        {
            helper[k++] = arr[ptr1++];
        }
        else
        {
            helper[k++] = arr[ptr2++];
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