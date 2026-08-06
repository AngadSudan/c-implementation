#include <stdio.h>

void insert(int num);
float getMedian();

int maxHeap[1000];
int minHeap[1000];

int maxSize = 0;
int minSize = 0;

int maxPeek();
int minPeek();

void maxInsert(int num);
void minInsert(int num);

int maxRemove();
int minRemove();

int main()
{
    while (1)
    {
        printf("Provide command [i(insert),g(getMedian)]");
        char choice;
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'g':
            printf("%f\n", getMedian());
            break;
        case 'i':
            int num;
            printf("Enter the number: ");
            scanf("%d", &num);
            insert(num);
            break;
        default:
            printf("Invalid command\n");
            break;
        }
    }
    return 0;
}

void insert(int num)
{
    if (maxSize == 0 || num <= maxPeek())
    {
        maxInsert(num);
    }
    else
    {
        minInsert(num);
    }

    if (maxSize > minSize + 1)
    {
        minInsert(maxRemove());
    }
    else if (minSize > maxSize + 1)
    {
        maxInsert(minRemove());
    }
}
float getMedian()
{
    if (maxSize == minSize)
    {
        return (maxPeek() + minPeek()) / 2.0f;
    }

    if (maxSize > minSize)
        return maxPeek();

    return minPeek();
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int maxPeek()
{
    return maxHeap[0];
}
void maxInsert(int num)
{
    int i = maxSize++;
    maxHeap[i] = num;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (maxHeap[parent] >= maxHeap[i])
            break;

        swap(&maxHeap[parent], &maxHeap[i]);
        i = parent;
    }
}
int maxRemove()
{
    int root = maxHeap[0];

    maxHeap[0] = maxHeap[--maxSize];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < maxSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if (right < maxSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&maxHeap[i], &maxHeap[largest]);
        i = largest;
    }

    return root;
}
int minPeek()
{
    return minHeap[0];
}
void minInsert(int num)
{
    int i = minSize++;
    minHeap[i] = num;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (minHeap[parent] <= minHeap[i])
            break;

        swap(&minHeap[parent], &minHeap[i]);
        i = parent;
    }
}
int minRemove()
{
    int root = minHeap[0];

    minHeap[0] = minHeap[--minSize];

    int i = 0;

    while (1)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < minSize && minHeap[left] < minHeap[smallest])
            smallest = left;

        if (right < minSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&minHeap[i], &minHeap[smallest]);
        i = smallest;
    }

    return root;
}