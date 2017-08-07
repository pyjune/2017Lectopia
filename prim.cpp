#include <stdio.h>

int adj[6][6];
int mst[6];
int V;
int E;
int mstEdge[4][2];

int prim(int n);

int main(void)
{
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2, w;
		scanf("%d %d %d", &n1, &n2, &w);
		adj[n1][n2] = w;
		adj[n2][n1] = w;
	}
	
	printf("%d\n", prim(1));
	for (int i = 0; i < V-1; i++)
	{
		printf("%d %d %d\n", mstEdge[i][0], mstEdge[i][1], adj[mstEdge[i][0]][mstEdge[i][1]]);
	}
}

int prim(int n)
{
	int cost = 0;
	int cnt = 1;
	// 시작 노드를 mst에 포함..
	mst[n] = 1;
	while (cnt < V)
	{
		int min = 0x7fffffff; // 주어진 가중치의 최대보다 크게 초기화
		int minV = 0;
		for (int i = 1; i <= V; i++)
		{
			if (mst[i] == 1) // mst에 포함된 노드 i에대해
			{
				for (int j = 1; j <= V; j++)
				{
					if (adj[i][j] != 0 && mst[j] == 0) // 인접이면서 mst에 포함되진 않는 j에 대해 비용이 최소인지 확인
					{
						if (adj[i][j] < min)
						{
							min = adj[i][j];
							minV = j;
							mstEdge[cnt - 1][0] = i;
							mstEdge[cnt - 1][1] = j;
						}
					}
				}
			}
		}
		mst[minV] = 1; // minV를 mst에 포함
		cnt++;
		cost += min;
	}
	return cost;
}
