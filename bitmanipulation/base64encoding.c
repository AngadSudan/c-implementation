#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *encode(char *ch, int n);
char *encodeToBinary(char *ch, int n);
int getRequiredPadding(int encodedLength);
int *splitBinary(char *ch, int n);
char *mapDecimal(int *arr, int n, int padding);

int main(void)
{
    char ch[1000];

    if (fgets(ch, sizeof(ch), stdin) == NULL)
        return 1;

    int n = strlen(ch);

    if (n > 0 && ch[n - 1] == '\n')
    {
        ch[n - 1] = '\0';
        n--;
    }

    printf("%s\n", encode(ch, n));

    return 0;
}

char *encode(char *ch, int n)
{
    char *encodedBinary = encodeToBinary(ch, n);
    int encodedLength = strlen(encodedBinary);
    int padding = getRequiredPadding(n);
    int *arr = splitBinary(encodedBinary, encodedLength);
    char *mappedValues = mapDecimal(arr, encodedLength / 6, padding);
    for (int i = 0; i < padding; i++)
    {
        mappedValues[encodedLength / 6 + i] = '=';
    }

    mappedValues[encodedLength / 6 + padding] = '\0';
    return mappedValues;
}
char *encodeToBinary(char *ch, int n)
{
    int totalBits = n * 8;

    int extraBits = (6 - (totalBits % 6)) % 6;

    char *output = malloc(totalBits + extraBits + 1);
    if (output == NULL)
        return NULL;

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        unsigned char value = (unsigned char)ch[i];

        for (int j = 7; j >= 0; j--)
        {
            output[k++] = (value & (1 << j)) ? '1' : '0';
        }
    }

    while (extraBits--)
    {
        output[k++] = '0';
    }

    output[k] = '\0';

    return output;
}

int *splitBinary(char *ch, int n)
{
    int groups = n / 6;

    int *result = malloc(groups * sizeof(int));

    if (result == NULL)
        return NULL;

    for (int i = 0; i < groups; i++)
    {
        int value = 0;

        for (int j = 0; j < 6; j++)
        {
            char bit = ch[(i * 6) + j];

            value = (value << 1) | (bit - '0');
        }

        result[i] = value;
    }

    return result;
}

char *mapDecimal(int *arr, int n, int padding)
{
    char *mappedResult = malloc(n + padding + 1);

    if (mappedResult == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        char ch;
        if (value >= 0 && value <= 25)
        {
            ch = ((char)(value + 65));
        }
        else if (value >= 26 && value <= 51)
        {
            ch = ((char)(value + 97 - 26));
        }
        else if (value >= 52 && value <= 61)
        {
            ch = value - 4;
        }
        else if (value == 62)
        {
            ch = '+';
        }
        else if (value == 63)
        {
            ch = '/';
        }
        mappedResult[i] = ch;
    }

    return mappedResult;
}
int getRequiredPadding(int encodedLength)
{
    if (encodedLength % 3 == 2)
    {
        return 1;
    }
    else if (encodedLength % 3 == 1)
    {
        return 2;
    }
    return 0;
}