#include <stdio.h>

void f(int n, int k);
void f2(int n, int k, int m);
int a[] = { 1, 6, 7 , 8, 9};
int p[3];

int main(void)
{
	//f(0, 3);
	f2(0, 3, 5);
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
void f2(int n, int k, int m)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			p[n] = a[i];
			f2(n + 1, k, m);
		}
	}
}
