#include <stdio.h>

int isPrime(int n); //함수의 원형(prototype)

int main()
{
	int n, i;
	scanf("%d", &n);
	int count = 0;

	for (i = 2; i <= n; i++) {
		if (isPrime(i) == 1)
			count++;
	}
	printf("%d\n", count);
	return 0;
}

int isPrime(int n)
{

	for (int i = 2; i*i <= n; i++)
		if (n % i == 0)
			return 0;


	return 1;

}

