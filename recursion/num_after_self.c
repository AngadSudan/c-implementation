#include <stdio.h>

typedef struct
{
    int value;
    int index;
} Node;

void countNumAfterSelf(Node arr[], int ans[], int n);
void numAfterSelf(Node arr[], int ans[], int start, int end);
void numHelper(Node arr[], int ans[], int start, int mid, int end);

int main(void)
{
    int n;
    scanf("%d", &n);

    Node arr[n];
    int ans[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        ans[i] = 0;
    }

    countNumAfterSelf(arr, ans, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}

void countNumAfterSelf(Node arr[], int ans[], int n)
{
    numAfterSelf(arr, ans, 0, n - 1);
}

void numAfterSelf(Node arr[], int ans[], int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    numAfterSelf(arr, ans, start, mid);
    numAfterSelf(arr, ans, mid + 1, end);

    numHelper(arr, ans, start, mid, end);
}

void numHelper(Node arr[], int ans[], int start, int mid, int end)
{
    int size = end - start + 1;
    Node helper[size];

    int ptr1 = start;
    int ptr2 = mid + 1;
    int k = 0;
    int rightCount = 0;

    while (ptr1 <= mid && ptr2 <= end)
    {
        if (arr[ptr2].value < arr[ptr1].value)
        {
            helper[k++] = arr[ptr2++];
            rightCount++;
        }
        else
        {
            ans[arr[ptr1].index] += rightCount;
            helper[k++] = arr[ptr1++];
        }
    }

    while (ptr1 <= mid)
    {
        ans[arr[ptr1].index] += rightCount;
        helper[k++] = arr[ptr1++];
    }

    while (ptr2 <= end)
    {
        helper[k++] = arr[ptr2++];
    }

    for (int i = 0; i < size; i++)
    {
        arr[start + i] = helper[i];
    }
}