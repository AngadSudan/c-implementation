#include <stdio.h>

int bitwiseAnd(int a, int b);
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ans = bitwiseAnd(a, b);
    printf("%d", ans);
    return 0;
}

int bitwiseAnd(int a, int b)
{
    return ~(~a | ~b);
}