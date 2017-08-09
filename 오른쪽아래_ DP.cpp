#include <stdio.h>

int t[101][101];
int d[101][101];
int N, M;

void find(void);
void find2(void);
int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);

	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				scanf("%d", &t[i][j]);
			}
		}
		//find();
		find2();
		printf("#%d %d\n", tc, d[N][M]);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				d[i][j] = 0;
			}
		}
	}

}
// 최대
void find(void)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			d[i][j] = (d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1]) + t[i][j];
		}
	}
}

// 최소
void find2(void)
{
	for (int j = 1; j <= M; j++)
		d[1][j] = d[1][j - 1] + t[1][j];
	for (int i = 1; i <= N; i++)
		d[i][1] = d[i - 1][1] + t[i][1];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j <= M; j++)
		{
			d[i][j] = (d[i - 1][j] < d[i][j - 1] ? d[i - 1][j] : d[i][j - 1]) + t[i][j];
		}
	}
}
