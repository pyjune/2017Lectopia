#include <stdio.h>

int a[3] = { 1, 2, 3 };
int b[3];

//배열 복사
void f(int n, int k);
// 배열 
int find(int n, int k, int v);

int main(void)
{
	f(0, 3);
	printf("%d %d %d\n", b[0], b[1], b[2]);
	int r = find(0, 3, 5);
	printf("%d\n", r);
}

void f(int n, int k)
{
	if (n == k)
	{
		return;
	}
	else
	{
		b[n] = a[n];
		f(n + 1, k);
	}
}
int find(int n, int k, int v)
{
	if (n == k)
	{
		return 0;
	}
	else if (a[n] == v)
	{
		return 1;
	}
	else
	{
		return find(n + 1, k, v);
	}
}
