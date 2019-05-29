int isPerfectNumber(int n)
{
	int sum = 0;

	for (int i = 1; i < n; i++)
		if (n%i == 0)
			sum += i;

	if (sum == n)
		return 1;
	else
		return 0;
}

#include <stdio.h>
int main()
{
	int count = 0;
	int i, n;
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		if (isPerfectNumber(i) == 1)
			count++;
	}

	printf("%d", count);
	return 0;
}
