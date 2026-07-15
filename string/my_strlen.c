#include <stdio.h>
#include <string.h>

int my_strlen(const char *str);

int main(void)
{
    char userInput[10000];
    fgets(userInput, sizeof(userInput), stdin);
    printf("%d\n", my_strlen(userInput));
    return 0;
}

int my_strlen(const char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        str++;
        length++;
    }
    return length;
}