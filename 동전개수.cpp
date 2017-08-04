#include <stdio.h>

int adj[101][101];
int ind[101];
int coin[101];
int V;
int E;
int Q[1000];
int front;
int rear;
int max;

void ts(void);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &V, &E);
		int n1, n2;
		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &n1, &n2);
			adj[n1][n2] = 1;
			ind[n2]++; // 진입차수
		}
		front = -1;
		rear = -1;
		max = 0;
		ts();
		printf("#%d %d\n", tc, max);

		for (int i = 1; i <= V; i++)
		{
			ind[i] = 0;
			coin[i] = 0;
			for (int j = 1; j <= V; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
}

void ts(void)
{
	// 초기화
	for (int i = 1; i <= V; i++)
	{
		if (ind[i] == 0)
		{
			Q[++rear] = i;
			coin[i] = 1;
		}
	}
	// 반복
	while (front != rear)
	{
		int n = Q[++front];
		for (int i = 1; i <= V; i++)
		{
			if (adj[n][i] == 1) // 인접인 노드 i의
			{
				ind[i]--;
				if (ind[i] == 0) // 동전개수를 결정할 수 있으면
				{
					coin[i] = coin[n] + 1;
					max = coin[i];
					Q[++rear] = i;

				}
			}
		}
	}
}
