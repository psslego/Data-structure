#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode *link;
}StackNode;

typedef struct {
	StackNode *top;
}LinkedStackType;

void init(LinkedStackType*sptr)
{
	sptr->top = NULL;
}
void push(LinkedStackType*sptr, element item)
{
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		printf("error");
		return;
	}
	else {
		temp->item = item;
		temp->link = sptr->top; //temp의 link는 sptr의 top이 가리키는 걸 가리키게 한다.
		sptr->top = temp; //sptr의 top은 temp를 가리키게 한다.
	}
}

int is_empty(LinkedStackType*sptr)
{
	if (sptr->top == NULL)
		return 1;
	return 0;
}

element pop(LinkedStackType*sptr)
{
	if (is_empty(sptr)) {
		printf("error");
	}
	else {
		StackNode*temp = sptr->top;
		int item = temp->item;
		sptr->top = sptr->top->link;
		free(temp);
		return item;
	}
}

void decimalTo_R_scale(int decimalNum, int r, char *RNum) {
	LinkedStackType L;
	int index = 0;
	if (decimalNum == 0) {
		RNum[0] = '0';
		RNum[1] = '\n';
		return;
	}
	init(&L); //스택 초기화
	while (decimalNum != 0) {
		int rem = decimalNum % r;
		if (rem < 10) { //나머지가 9이하인 경우 ‘0’을 더해 문자로 변환
			push(&L, '0' + rem);
		}
		else { //나머지가 10이상인 경우 ‘A’을 더해 문자로 변환
			push(&L, 'A' + rem - 10);
		}
		decimalNum = decimalNum / r;
	}
	while (!is_empty(&L)) { //스택이 비워질 때까지 pop
		RNum[index] = pop(&L);
		index++;
	}

	RNum[index] = '\0'; //RNum의 마지막 index에 ‘\0’을 채우면서 문자배열 완성
}

int main() {
	int n, r;
	char RNum[20];
	scanf("%d%d", &n, &r);
	decimalTo_R_scale(n, r, RNum);
	printf("%s\n", RNum);
	return 0;
}
