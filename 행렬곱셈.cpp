#include <stdio.h>

int p[11];
int m[11][11];
int N;
int r;

int find(void);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		r = 1;
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		p[0] = n1;
		p[1] = n2;
		for (int i = 2; i <= N; i++)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);
			if (p[i - 1] != n1)
				r = 0;
			p[i - 1] = n1;
			p[i] = n2;
		}
		if (r == 1)
			r = find();
		printf("#%d %d\n", tc, r);
		
	}
}

int find(void)
{
	for (int l = 1; l < N; l++)
	{
		for (int i = 1; i <= N - l; i++)
		{
			int j = i + l;
			int min = 0x7fffffff;
			for (int k = i; k < j; k++)
			{
				int tmp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (tmp < min)
					min = tmp;
			}
			m[i][j] = min;
		}
	}
	return m[1][N];
}
