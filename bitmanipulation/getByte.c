#include <stdio.h>

int getByte(int a, int n);
int main(void)
{
    int a, n;
    scanf("%d %d", &a, &n);

    int ans = getByte(a, n);
    printf("%d", ans);
    return 0;
}

int getByte(int a, int n)
{
    return (a >> (n * 8)) & 0xFF;
}
