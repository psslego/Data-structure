#include <stdio.h>
#include<string.h>
#define MAX 1000

typedef char element;

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
		printf("Stack Enpty Error\n");
		return 0;
	}
	element item = s->stack[(s->top)--];
	return item;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

void decimalTo_R_scale(int decimalNum, int r, char *RNum) {
	StackType s;
	int index = 0;
	if (decimalNum == 0) {
		RNum[0] = '0';
		RNum[1] = '\n';
		return;
	}
	init(&s);
	while (decimalNum != 0) {
		int rem = decimalNum % r;
		if (rem < 10) {
			push(&s, '0' + rem);
		}
		else {
			push(&s, 'A' + rem - 10);
		}
		decimalNum = decimalNum / r;
	}
	while (!is_empty(&s)) {
		RNum[index] = pop(&s);
		index++;
	}

	RNum[index] = '\0';
}

int main() {
	int n, r;
	char RNum[MAX];
	scanf("%d%d", &n, &r);
	decimalTo_R_scale(n, r, RNum);
	printf("%s\n", RNum);
	return 0;
}

