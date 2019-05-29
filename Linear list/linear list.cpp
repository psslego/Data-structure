#include <stdio.h>
#include <string.h>
#define MAX_LIST_SIZE 10000

typedef int element;

typedef struct {
	int list[MAX_LIST_SIZE];
	int length;
}ArrayListType;

void init(ArrayListType*L)
{
	L->length = 0;
}

int is_empty(ArrayListType*L)
{
	return L->length == 0;
}

int is_full(ArrayListType*L)
{
	return L->length == MAX_LIST_SIZE;
}
void add(ArrayListType*L, int position, element item)
{
	if (!is_full(L) && (position >= 0)
		&& (position <= L->length)) {
		int i;
		for (i = (L->length - 1); i >= position; i--)
			L->list[i + 1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}

void delete(ArrayListType*L, int position)
{
	int i;
	element item;
	if (position < 0 || position >= L->length)
		printf("위치오류");
	item = L->list[position];
	for (i = position; i < (L->length - 1); i++)
		L->list[i] = L->list[i + 1];
	L->length--;
}

int is_in_list(ArrayListType*L, element item)
{
	int i;
	for (i = 0; i < (L->length); i++)
		if (L->list[i] == item)
			return 1;
	return 0;
}

void replace(ArrayListType*L, int position, element item)
{
	L->list[position] = item;
}

/*void add_last(ArrayListType*L, element item)
{
	L->list[L->length] = item;
}

void add_first(ArrayListType*L, element item)
{
	int i;
	if (!is_full(L))
		for (i = L->length - 1; i < 0; i--)
			L->list[i + 1] = L->list[i];
	L->list[0] = item;
}*/

int get_entry(ArrayListType*L, int position)
{
	return L->list[position];
}

int get_length(ArrayListType*L)
{
	return L->length;
}

int print(ArrayListType*L)
{
	for (int i = 0; i < L->length; i++)
		printf("%d", L->list[i]);
	return 0;
}

int main()
{
	ArrayListType L;
	char command[20];
	int position = 0;
	int item = 0;
	while (1) {
		scanf("%s", &command);
		if (strcmp(command, "리스트초기화") == 0) {
			init(&L);
		}
		else if (strcmp(command, "원소삽입") == 0) {
			scanf("%d%d", &position, &item);
			add(&L, position, item);
		}
		else if (strcmp(command, "원소삭제") == 0) {
			scanf("%d", &position);
			delete(&L, position);
		}
		else if (strcmp(command, "원소변경") == 0) {
			scanf("%d%d", &position, &item);
			replace(&L, position, item);
		}
		else if (strcmp(command, "원소확인") == 0) {
			scanf("%d", &position);
			item = get_entry(&L, position);
			printf("%d\n", item);
		}
		else if (strcmp(command, "리스트출력") == 0) {
			print(&L);
		}
		else if (strcmp(command, "종료") == 0) {
			break;
		}
	}
	return 0;
}