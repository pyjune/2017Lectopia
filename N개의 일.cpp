#include <stdio.h>

int N;
int t[10][10];
int p[10];
int u[10];
int minValue;
int cnt;

void npr(int n, int k);
void npr2(int n, int k, int s);
int main(void)
{
	int T;

	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		minValue = 0x7fffffff;
		cnt = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%d", &t[i][j]);
			}
		}
		npr2(0, N, 0);
		printf("#%d %d %d\n", tc, minValue, cnt);
	}

}

void npr(int n, int k)
{

	if (n == k)
	{
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			//printf("%d ", p[i]);
			sum += t[p[i]][i];
		}
		if (sum < minValue)
			minValue = sum;
		//printf("\n");
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (u[i] == 0)
			{
				p[n] = i;
				u[i] = 1;
				npr(n + 1, k);
				u[i] = 0;
			}
		}
	}
}

void npr2(int n, int k, int s)
{
	cnt++;
	if (n == k)
	{
		
		if (s < minValue)
			minValue = s;
		//printf("\n");
	}
	else if (s >= minValue)
	{
		return;
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (u[i] == 0)
			{
				p[n] = i;
				u[i] = 1;
				npr2(n + 1, k, s+t[p[n]][n]);
				u[i] = 0;
			}
		}
	}
}
