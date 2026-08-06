#include <stdio.h>
int numOfVillages(int arr[], int n, int k);
int canAllocate(int arr[], int n, int k, int maxLoad);

int main(void)
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int k;
    scanf("%d", &k);
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", numOfVillages(arr, n, k));
    return 0;
}

int canAllocate(int arr[], int n, int k, int maxLoad)
{
    int clinics = 0;
    for (int i = 0; i < n; i++)
    {
        clinics += (arr[i] + maxLoad - 1) / maxLoad;
    }
    return clinics <= k;
}

int numOfVillages(int arr[], int n, int k)
{
    int start = 1;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        end = end > arr[i] ? end : arr[i];
    }

    int result = end;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (canAllocate(arr, n, k, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}
