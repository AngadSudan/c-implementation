#include <stdio.h>
#include <string.h>

int main(void)
{
    char string[] = "C,C++,Java,Python,Rust";
    char *token = strtok(string, ",");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}