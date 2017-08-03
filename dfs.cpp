#include <stdio.h>

void dfs(int n);
void dfs2(int n, int k);
void dfs3(int n, int k, int e);

int m[11][11];
int visited[11];

int V;
int E;
int cnt;
int min;

int main(void)
{
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		m[n1][n2] = 1;
//		 m[n2][n1] = 1; // 무향인 경우
	}
	//dfs(1);
	cnt = 0;
	min = 0x7fffffff;
	//dfs2(1, 4);
	//printf("%d\n", cnt);
	dfs3(1, 4, 0);
	printf("%d\n", min);
}

void dfs(int n)
{
	visited[n] = 1;
	printf("%d ", n);
	for (int i = 1; i <= V; i++)
	{
		if (m[n][i] == 1 && visited[i] == 0)
		{
			dfs(i);
		}
	}
}

void dfs2(int n, int k)
{
	if (n == k)
	{
		cnt++;
	}
	else
	{
		visited[n] = 1;
		for (int i = 1; i <= V; i++)
		{
			if (m[n][i] == 1 && visited[i] == 0)
			{
				dfs2(i, k);
			}
		}
		visited[n] = 0;
	}
}

void dfs3(int n, int k, int e)
{
	if (n == k)
	{
		if (min > e)
			min = e;
	}
	else
	{
		visited[n] = 1;
		for (int i = 1; i <= V; i++)
		{
			if (m[n][i] == 1 && visited[i] == 0)
			{
				dfs3(i, k, e+1);
			}
		}
		visited[n] = 0;
	}
}
