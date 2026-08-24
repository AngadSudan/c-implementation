#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool is_opening(char c)
{
    return c == '(' || c == '[' || c == '{';
}

static bool matches(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

static bool is_balanced(const char *expression)
{
    char stack[31];
    size_t top = 0;

    for (size_t i = 0; expression[i] != '\0'; ++i)
    {
        char current = expression[i];

        if (is_opening(current))
        {
            if (top == sizeof stack)
            {
                return false;
            }
            stack[top++] = current;
        }
        else if (current == ')' || current == ']' || current == '}')
        {
            if (top == 0 || !matches(stack[--top], current))
            {
                return false;
            }
        }
    }

    return top == 0;
}

int main(void)
{
    char expression[32] = "";

    scanf("%31s", expression);
    printf("%s\n", is_balanced(expression) ? "true" : "false");
    return 0;
}
