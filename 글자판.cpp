#include <stdio.h>

char m[100][101];
int v[100][100];
int N;
char str[101];

int strLen(char *p);
int find(int r, int c, int n, int k);

int main(void)
{
	int T;
	int r =0;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		scanf("%s", str);

		for (int i = 0; i < N; i++)
		{
			scanf("%s", m[i]);
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (m[i][j] == str[0])
				{
					r = find(i, j, 1, strLen(str));
					if (r == 1)
						break;
				}
			}
			if (r == 1)
				break;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				v[i][j] = 0;
		}
		printf("%d %d\n", tc, r);
	}

	return 0;
}

int strLen(char *p)
{
	int i = 0;
	while (p[i] != '\0')
	{
		i++;
	}
	return i;
}

int find(int r, int c, int n, int k)
{
	
	if (n == k) //if(str[n]=='\0')
	{
		return 1;
	}
	else
	{
		v[r][c] = 1;
		if ((c + 1 < N) && (v[r][c+1]==0) && (m[r][c + 1] == str[n]))
		{
			if (find(r, c + 1, n + 1, k) == 1)
				return 1;
		}
		if ((r + 1 < N) && (v[r+1][c] == 0) && (m[r + 1][c] == str[n]))
		{
			if (find(r + 1, c, n + 1, k) == 1)
				return 1;
		}
		if ((c - 1 >= 0) && (v[r][c - 1] == 0) && (m[r][c - 1] == str[n]))
		{
			if (find(r, c - 1, n + 1, k) == 1)
				return 1;
		}
		if ((r - 1 >= 0) && (v[r-1][c] == 0) && (m[r - 1][c] == str[n]))
		{
			if (find(r - 1, c, n + 1, k) == 1)
				return 1;
		}
		v[r][c] = 0;
		return 0;
	}
}
