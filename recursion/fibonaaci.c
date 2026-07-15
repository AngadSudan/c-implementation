#include <stdio.h>

int sumEvenFibonacciBruteForce(int n)
{
    int a = 1, b = 1;
    int sum = 0;

    while (a <= n)
    {
        if (a % 2 == 0)
        {
            sum += a;
        }

        int next = a + b;
        a = b;
        b = next;
    }

    return sum;
}

int sumEvenFibonacciOptimized(int n)
{
    if (n < 2)
    {
        return 0;
    }

    int sum = 0;
    int even1 = 2;
    int even2 = 8;

    while (even1 <= n)
    {
        sum += even1;

        int nextEven = 4 * even2 + even1;
        even1 = even2;
        even2 = nextEven;
    }

    return sum;
}

int main(void)
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    int bruteForceSum = sumEvenFibonacciBruteForce(n);
    int optimizedSum = sumEvenFibonacciOptimized(n);

    return 0;
}
