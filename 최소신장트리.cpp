#include <stdio.h>

int adj[101][101];
int mst[101];
int V;
int E;
int mstEdge[100][2];

int prim(int n);
// prim2()
void enQ(int n1, int n2, int w);
int deQ(void);
int t[3]; // deQ()의 결과 저장..t[0], t[1] node번호, t[2] 비용..

int main(void)
{
	freopen("Text.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++)
		{
			int n1, n2, w;
			scanf("%d %d %d", &n1, &n2, &w);
			adj[n1][n2] = w;
			adj[n2][n1] = w;
		}

		printf("#%d %d\n", tc, prim(0));
		//	for (int i = 0; i < V-1; i++)
		//	{
		//		printf("%d %d %d\n", mstEdge[i][0], mstEdge[i][1], adj[mstEdge[i][0]][mstEdge[i][1]]);
		//	}
		for (int i = 0; i <= V; i++)
		{
			mst[i] = 0;
			for (int j = 0; j <= V; j++)
			{
				adj[i][j] = 0;
			}
		}
	}
}

int prim(int n)
{
	int cost = 0;
	int cnt = 1;
	// 시작 노드를 mst에 포함..
	mst[n] = 1;
	while (cnt <= V)
	{
		int min = 0x7fffffff; // 주어진 가중치의 최대보다 크게 초기화
		int minV = 0;
		for (int i = 0; i <= V; i++)
		{
			if (mst[i] == 1) // mst에 포함된 노드 i에대해
			{
				for (int j = 0; j <= V; j++)
				{
					if (adj[i][j] != 0 && mst[j] == 0) // 인접이면서 mst에 포함되진 않는 j에 대해 비용이 최소인지 확인
					{
						if (adj[i][j] < min)
						{
							min = adj[i][j];
							minV = j;
							//mstEdge[cnt - 1][0] = i;
							//mstEdge[cnt - 1][1] = j;
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
/*
int prim2(int n)
{
	int cost = 0;
	int cnt = 1;
	// 시작 노드의 모든 인접 노드를 enQ()
	for (int i = 1; i <= V; i++)
	{
		if (adj[n][i] != 0)
		{
			enQ(n, i, adj[n][i]);
		}
	}
	mst[n] = 1; // 시작 노드를 mst에 포함

	while (cnt<V)
	{
		deQ();
		if (mst[t[1]] != 0) // (t[1] 노드가 mst에 포함되어 있지 않으면)
		{
			mst[t[1]] = 1;
			cnt++;
			cost += adj[t[0]][t[1]];
			for (int i = 1; i <= V; i++)
			{
				if (adj[t[1]][i] != 0 && mst[i] == 0)
				{
					enQ(t[1], i, adj[t[1]][i]);
				}
			}
		}
	}
	return cost;
}

*/
