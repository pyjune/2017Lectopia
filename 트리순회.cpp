#include <stdio.h>

int V;
int E;
int ch1[11]; // 노드가 10개라면..
int ch2[11];
int par[11]; // 자식을 인덱스로 부모 저장

void DLR(int n);
void LDR(int n);
void LRD(int n);

int main(void)
{
	freopen("Text.txt", "r", stdin);
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int p, c;
		scanf("%d %d", &p, &c);
		if (ch1[p] == 0)
		{
			ch1[p] = c;
		}
		else
		{
			ch2[p] = c;
		}
		par[c] = p;
	}
	DLR(1);
	printf("\n");
	LDR(1);
	printf("\n");
	LRD(1);
	printf("\n");
}

void DLR(int n)
{
	printf("%d ", n);
	if (ch1[n] != 0)
		DLR(ch1[n]);
	if (ch2[n] != 0)
		DLR(ch2[n]);
}

void LDR(int n)
{
	
	if (ch1[n] != 0)
		LDR(ch1[n]);
	printf("%d ", n);
	if (ch2[n] != 0)
		LDR(ch2[n]);
}

void LRD(int n)
{
	
	if (ch1[n] != 0)
		LRD(ch1[n]);
	if (ch2[n] != 0)
		LRD(ch2[n]);
	printf("%d ", n);
}
