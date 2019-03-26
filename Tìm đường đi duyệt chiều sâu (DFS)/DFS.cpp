#include <stdio.h>
#include<conio.h>
#define MAX 100
#define inputfile "DFS.txt"

int LuuVet[MAX];
int ChuaXet[MAX];

typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}DoThi;

int DocMaTran(char TenFile[100],DoThi &g)
{
	FILE *f; // tao bien FILE
	f = fopen(TenFile,"rt");// mo mot file co duong dan luu o bien TenFile
	if(f == NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	int i,j;
	for(i = 0;i<g.n;i++)
	{
		for(j = 0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}

void XuatMaTran(DoThi g)
{
	printf("So dinh cua ma tran: %d\n",g.n);
	printf("Ma tran co do thi la:\n");
	for(int i = 0;i<g.n;i++)
	{
		for(int j = 0;j<g.n;j++)
		{
			printf("%5d",g.a[i][j]);
		}
		printf("\n");
	}
}

void DFS(int v,DoThi g)
{
	ChuaXet[v] = 1;
	int u;
	for(u=0;u<g.n;u++)
	{
		if(g.a[v][u] != 0 && ChuaXet[u] == 0)
		{
			LuuVet[u] = v;
			DFS(u,g);
		}
	}
}

void duyettheoDFS(int S, int F, DoThi g)
{
	int i;
	for(int i = 0;i<g.n;i++)
	{
		LuuVet[i] = -1;
		ChuaXet[i] = 0;
	}
	DFS(S,g);
	if(ChuaXet[F] == 1)
	{
		printf("Duong di tu dinh %d den dinh %d la:\n\t",S,F);
		i = F;
		printf("%c",F+'A');
		while(LuuVet[i] != S)
		{
			printf("<- %c",LuuVet[i] + 'A');
			i=LuuVet[i];
		}
		printf("<-%c\n",LuuVet[i]+'A');
	}
	else
	{
		printf("Khong co duong di tu dinh %d  den dinh %d \n",S,F);
	}
}

int main() {
	DoThi g;
	if(DocMaTran(inputfile,g) == 1)
	{
		XuatMaTran(g);
		duyettheoDFS(0,10,g);
	}
	getch();
	return 0;
}

