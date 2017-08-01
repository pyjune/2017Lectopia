#include <stdio.h>

void f(int n, int k);
int a[] = { 1, 6, 7 };
int p[3];

int main(void)
{
	f(0, 3);
}

void f(int n, int k)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		//for (int i = 1; i <=k ; i++)
		for (int i = 0; i < k; i++)
		{
			//p[n] = i;
			p[n] = a[i];
			f(n + 1, k);
		}
	}
}
