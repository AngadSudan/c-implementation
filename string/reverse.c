#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10000
void reverseString(char *inputString);

int main(void)
{
    char userInput[BUFFER_SIZE];
    fgets(userInput, BUFFER_SIZE, stdin);
    reverseString(userInput);
    printf("%s", userInput);
    return 0;
}

void reverseString(char *inputString)
{
    char *start = inputString;
    char *end = inputString + strlen(inputString) - 2;
    ;

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}