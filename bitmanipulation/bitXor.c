#include <stdio.h>

int bitwiseXor(int a, int b);
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    int ans = bitwiseXor(a, b);
    printf("%d", ans);
    return 0;
}

int bitwiseXor(int a, int b)
{
    return ~(~(a & ~b) & ~(~a & b));
}
