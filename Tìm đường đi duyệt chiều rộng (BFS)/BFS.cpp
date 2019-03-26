#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
#define inputfile "BFS.txt"

int LuuVet[MAX];
int ChuaXet[MAX];

typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
}DoThi;

struct QUEUE{
	int size;
	int array[MAX];
};

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

void KhoiTaoQueue(QUEUE &Q)
{
	Q.size = 0;
}

int DayGiaTriVaoQueue(QUEUE &Q,int value)
{
	if(Q.size + 1 >= 100)
	{
		return 0;
	}
	Q.array[Q.size] = value;
	Q.size++;
	return 1;
}

int LayGiaTriRaKhoiQueue(QUEUE &Q,int &value)
{
	if(Q.size <= 0)
	{
		return 0;
	}
	value = Q.array[0];
	for(int i = 0 ; i < Q.size - 1;i++)
	{
		Q.array[i] = Q.array[i+1];
	}
	Q.size--;
	return 1;
}

int KiemTraQueueRong(QUEUE Q)
{
	if(Q.size <= 0)
	{
		return 1;
	}
	return 0;
}

void BFS(int v, DoThi g)
{
	QUEUE Q;
	KhoiTaoQueue(Q);
	DayGiaTriVaoQueue(Q,v);
	while(!KiemTraQueueRong(Q))
	{
		LayGiaTriRaKhoiQueue(Q,v);
		ChuaXet[v] = 1;
		for(int u = 0;u<g.n;u++)
		{
			if(g.a[v][u] != 0 && ChuaXet[u] == 0)
			{
				DayGiaTriVaoQueue(Q,u);
				if(LuuVet[u] == -1)
				{
					LuuVet[u] = v;
				}
			}
		}
	}
}

void XuatBFS_Xuoi(int i, int S)
{
	if(i!=S)
	{
		XuatBFS_Xuoi(LuuVet[i], S);
		printf(" -> %d", i+1);
	}
}
void duyettheoBFS(int S, int F, DoThi g)
{
	int i;
	for(i = 0; i < g.n; i++)
	{
		LuuVet[i] = -1;
		ChuaXet[i] = 0;
	}
	BFS(S,g);
	printf("\n");
	for(i = 0; i < g.n; i++)
		printf("%d ",LuuVet[i]);
	if(ChuaXet[F] == 1)
	{
		printf("\nDuong di tu dinh %c den dinh %c.\n",S + 'A',F + 'A');
		i = F;
		printf("%d", S+1);
		XuatBFS_Xuoi(i,S);
	}
	else
		printf("Khong co duong di tu dinh %c den dinh %c.\n",S + 'A',F + 'A');
}
int main()
{
	DoThi g;
	if(DocMaTran(inputfile,g) == 1)
	{
		printf("Da lay thong tin do thi tu file thanh cong. \n\n");
		XuatMaTran(g);
		duyettheoBFS(0,10,g);
	}
	else
		printf("Doc file that bai.");
	getch();
	return 0;
}

