#include <stdio.h>

int printMatrix(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d ", *((arr + i) + j));
        }
        printf("\n");
    }
    return 0;
}
int setMatrixZero(int *arr, int size)
{
    int firstRow = 0;
    int firstCol = 0;

    for (int j = 0; j < size; j++)
    {
        if (*(arr + j) == 0)
        {
            firstRow = 1;
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (*(arr + i * size) == 0)
        {
            firstCol = 1;
            break;
        }
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (*(arr + i * size + j) == 0)
            {
                *(arr + j) = 0;
                *(arr + i * size) = 0;
            }
        }
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (*(arr + j) == 0 || *(arr + i * size) == 0)
            {
                *(arr + i * size + j) = 0;
            }
        }
    }

    if (firstRow)
    {
        for (int j = 0; j < size; j++)
            *(arr + j) = 0;
    }

    if (firstCol)
    {
        for (int i = 0; i < size; i++)
            *(arr + i * size) = 0;
    }

    return 0;
}
int main()
{
    int arr[][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setMatrixZero(&arr[0][0], 3);
    printMatrix(&arr[0][0], 3);
}