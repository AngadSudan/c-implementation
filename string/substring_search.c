#include <stdio.h>

#define BUFFER_SIZE 10000
int findSubstring(
    const char *haystack,
    const char *needle);

int main(void)
{
    char haystack[BUFFER_SIZE];
    fgets(haystack, BUFFER_SIZE, stdin);

    char needle[BUFFER_SIZE];
    fgets(needle, BUFFER_SIZE, stdin);

    int startIndex = findSubstring(haystack, needle);
    printf("%d\n", startIndex);
    return 0;
}

int findSubstring(
    const char *haystack,
    const char *needle)
{
    int index = 0;
    while (*haystack != '\0')
    {
        const char *temp1 = haystack;
        const char *temp2 = needle;

        while (*temp1 != '\0' &&
               *temp2 != '\0' &&
               *temp1 == *temp2)
        {
            temp1++;
            temp2++;
        }

        if (*temp2 == '\0')
        {
            return index;
        }

        haystack++;
        index++;
    }

    return -1; // substring not found
}