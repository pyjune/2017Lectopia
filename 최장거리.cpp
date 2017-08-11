#include <stdio.h>

int V;
int E;
int adj[1001][1001]; // 인접행렬
int maxlen[1001]; // 노드별 최장거리
int ind[1001]; // 진입차수
int q[1000000];

void tsort(void);

int main(void)
{

	int T;
	int n1, n2, w;
	freopen("Text.txt","r",stdin);
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &V, &E);
		for (int i = 0; i <= V; i++)
		{
			ind[i] = 0;
			for (int j = 0; j <= V; j++)
			{
				adj[i][j] = 0;
			}
		}
		for (int i = 0; i<E; i++)
		{
			scanf("%d %d %d", &n1, &n2, &w);
	
			adj[n1][n2] = w;
			ind[n2]++;	// 진입차수
		}
		tsort();
		printf("#%d %d\n", tc, maxlen[V]);
	}

}

void tsort(void)
{
	int front = -1;
	int rear = -1;

	for (int i = 0; i <= V; i++)
	{
		if (ind[i] == 0)	// 진입차수 0이면 enQ();
			q[++rear] = i;
	}
	while (front != rear)  // q가 비어있지 않으면 반복
	{
		int t = q[++front]; // deQ();
		int max = 0;
		// visit(t)
		for (int i = 0; i <= V; i++) // t까지의 가장 큰 진입 비용 찾기
		{
			if (adj[i][t] != 0)
			{
				if (maxlen[i] + adj[i][t]>max)
					max = maxlen[i] + adj[i][t];
			}
		}
		maxlen[t] = max;
		// t의 인접노드에 대해 진입차수 감소..
		for (int i = 0; i <= V; i++)
		{
			if (adj[t][i] != 0)
			{
				ind[i]--;
				if (ind[i] == 0) // i의 진입차수가 0이 되면 enQ()
					q[++rear] = i;
			}
		}
	}
}
