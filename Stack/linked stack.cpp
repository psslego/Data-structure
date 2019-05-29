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
		temp->link = sptr->top; //temp�� link�� sptr�� top�� ����Ű�� �� ����Ű�� �Ѵ�.
		sptr->top = temp; //sptr�� top�� temp�� ����Ű�� �Ѵ�.
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
	init(&L); //���� �ʱ�ȭ
	while (decimalNum != 0) {
		int rem = decimalNum % r;
		if (rem < 10) { //�������� 9������ ��� ��0���� ���� ���ڷ� ��ȯ
			push(&L, '0' + rem);
		}
		else { //�������� 10�̻��� ��� ��A���� ���� ���ڷ� ��ȯ
			push(&L, 'A' + rem - 10);
		}
		decimalNum = decimalNum / r;
	}
	while (!is_empty(&L)) { //������ ����� ������ pop
		RNum[index] = pop(&L);
		index++;
	}

	RNum[index] = '\0'; //RNum�� ������ index�� ��\0���� ä��鼭 ���ڹ迭 �ϼ�
}

int main() {
	int n, r;
	char RNum[20];
	scanf("%d%d", &n, &r);
	decimalTo_R_scale(n, r, RNum);
	printf("%s\n", RNum);
	return 0;
}
