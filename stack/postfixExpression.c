#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { STACK_CAPACITY = 128 };

typedef struct {
	double values[STACK_CAPACITY];
	size_t size;
} Stack;

static int stack_push(Stack *stack, double value)
{
	if (stack->size >= STACK_CAPACITY)
		return 0;
	stack->values[stack->size++] = value;
	return 1;
}

static int stack_pop(Stack *stack, double *value)
{
	if (stack->size == 0)
		return 0;
	*value = stack->values[--stack->size];
	return 1;
}

int main(void)
{
	char expression[256];
	Stack stack = { { 0 }, 0 };

	if (fgets(expression, sizeof(expression), stdin) == NULL)
		return 0;

	for (char *token = strtok(expression, " \t\n"); token != NULL;
		 token = strtok(NULL, " \t\n")) {
		char *end;
		double value = strtod(token, &end);

		if (*end == '\0') {
			if (!stack_push(&stack, value))
				return 1;
		} else if (token[1] == '\0' &&
				   (token[0] == '+' || token[0] == '-' ||
					token[0] == '*' || token[0] == '/')) {
			double left, right;

			if (!stack_pop(&stack, &right) ||
				!stack_pop(&stack, &left))
				return 1;

			switch (token[0]) {
			case '+': value = left + right; break;
			case '-': value = left - right; break;
			case '*': value = left * right; break;
			case '/':
				if (right == 0)
					return 1;
				value = left / right;
				break;
			}
			if (!stack_push(&stack, value))
				return 1;
		} else {
			return 1;
		}
	}

	if (stack.size != 1)
		return 1;

	if (stack.values[0] == (long long)stack.values[0])
		printf("%.0f\n", stack.values[0]);
	else
		printf("%g\n", stack.values[0]);

	return 0;
}
