#include <stdio.h>

#define BUFFER_SIZE 10000

void url_encode(char *str, int trueLength);

int main(void)
{
    char userInput[BUFFER_SIZE];
    fgets(userInput, BUFFER_SIZE, stdin);

    int trueLength;
    scanf("%d", &trueLength);

    url_encode(userInput, trueLength);
    printf("%s\n", userInput);

    return 0;
}

void url_encode(char *str, int trueLength)
{
    int spaces = 0;

    for (int i = 0; i < trueLength; i++)
    {
        if (str[i] == ' ')
        {
            spaces++;
        }
    }

    int newLength = trueLength + spaces * 2;
    str[newLength] = '\0';

    int i = trueLength - 1;
    int j = newLength - 1;

    while (i >= 0)
    {
        if (str[i] == ' ')
        {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        }
        else
        {
            str[j--] = str[i];
        }

        i--;
    }
}