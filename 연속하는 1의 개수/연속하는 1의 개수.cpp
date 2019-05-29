#include<stdio.h>
int main()
{
	int n;
	int data[10000];
	int i;
	int maxCnt, currentCnt;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &data[i]);

	if (data[0] == 1)
		currentCnt = maxCnt = 1;

	else
		currentCnt = maxCnt = 0;

	for (i = 1; i < n; i++) {
		if (data[i] == 1) {
			currentCnt++;
			if (currentCnt > maxCnt)
				maxCnt = currentCnt;
		}

		else
			currentCnt = 0;

	}
	printf("%d", maxCnt);
	return 0;
}