#include <stdio.h>

int p[3];
int a[] = { 1, 2, 3 , 4, 5};
int u[5];

void npr(int n, int k);
void npr2(int n, int k, int m);

int main(void)
{
	//npr(0, 3);
	npr2(0, 3, 5);
}

void npr(int n, int k)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (u[i] == 0)
			{
				p[n] = a[i];
				u[i] = 1;
				npr(n + 1, k);
				u[i] = 0;
			}
		}
	}
}
void npr2(int n, int k, int m)
{
	if (n == k)
	{
		for (int i = 0; i < k; i++)
		{
			printf("%d ", p[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (u[i] == 0)
			{
				p[n] = a[i];
				u[i] = 1;
				npr2(n + 1, k, m);
				u[i] = 0;
			}
		}
	}
}
