#include <stdio.h>
#define MAX 10000
int main()
{
	int n;
	int number[MAX];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &number[i]);

	int majority1, majority2;
	int SIZE = 0; /*과반수인 수의 개수*/

	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
			if (number[i] == number[j])
				cnt++;
		if (cnt >= (n + 1) / 2)
		{
			if (SIZE == 0) {
				majority1 = number[i];
				SIZE++;
			}
			else if (SIZE == 1)
			{
				if (majority1 != number[i]) {
					majority2 = number[i];
					SIZE++;
					break;
				}
			}
		}
	}
	if (SIZE == 0)
		printf(" -1");
	else if (SIZE == 1)
		printf("%d", majority1);
	if (SIZE == 2)
	{
		if (majority1 > majority2)
			printf("%d%d", majority2, majority1);
		else
			printf("%d%d", majority1, majority2);
	}
	return 0;
}