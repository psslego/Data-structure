#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10000

typedef int element;

typedef struct {
	element stack[MAX];
	int top;
} StackType;

void init(StackType *s) {
	s->top = -1;
}

void push(StackType *s, element item) {
	if (s->top == MAX - 1) {
		printf("Stack Full Error\n");
		return;
	}
	s->stack[++(s->top)] = item;
}

element pop(StackType *s) {
	if (s->top == -1) {
		printf("Stack Empty Error\n");
		return;
	}
	element item = s->stack[(s->top)--];
	return item;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

int main()
{
	char token[20];
	StackType s;
	int first, second, result;

	init(&s);
	scanf("%s", token);

	while (strcmp(token, ";") != 0) {

		if (isdigit(token[0])) {
			push(&s, atoi(token));
		}

		else if (token[0] == '-' && isdigit(token[1])) {
			push(&s, atoi(token));
		}

		else if (strcmp(token, "+") == 0) {
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			second = pop(&s);
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			first = pop(&s);
			push(&s, (first + second));
		}

		else if (strcmp(token, "-") == 0) {
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			second = pop(&s);
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			first = pop(&s);
			push(&s, (first - second));
		}
		else if (strcmp(token, "*") == 0) {
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			second = pop(&s);
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			first = pop(&s);
			push(&s, (first * second));
		}
		else if (strcmp(token, "/") == 0) {
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			second = pop(&s);
			if (is_empty(&s)) {
				printf("error\n");
				return 0;
			}
			first = pop(&s);
			push(&s, first / second);
		}
		scanf("%s", token);
	}
	result = pop(&s);

	if (is_empty(&s)) {
		printf("%d", result);
	}
	else {
		printf("error\n");
	}
	return 0;
}