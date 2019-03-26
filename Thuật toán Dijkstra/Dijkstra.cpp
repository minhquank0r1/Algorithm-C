#include<stdio.h>
#include<conio.h>
#define MAX 20
#define VOCUC 1000
#define inputfile "Dijkstra.txt"
int LuuVet[MAX];
int ChuaXet[MAX];
int DoDaiDuongDiToi[MAX];
typedef struct DoThi
{
	int n;
	int a[MAX][MAX];
}DOTHI;
int DocFile(char file[100], DOTHI &g)
{
	FILE *f;
	f = fopen(inputfile,"rt");
	if(f == NULL)
	{
		printf("Khong mo duoc file.");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0; i < g.n; i++)
	{
		for(int j = 0; j < g.n; j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void XuatMaTranKe(DOTHI g)
{
	printf("\nSo dinh cua do thi: %d",g.n);
	printf("\nMa tran cua do thi:\n");
	for(int i = 0; i < g.n; i++)
	{
		for(int j = 0; j < g.n;j++)
			printf("%3d",g.a[i][j]);
		printf("\n");
	}
}
int TimDuongDiNhoNhat(DOTHI g)
{
	int li = -1;
	float p = VOCUC;
	for(int i = 0; i < g.n; i++)
	{
		if(ChuaXet[i] == 0 && DoDaiDuongDiToi[i] < p)
		{
			p = DoDaiDuongDiToi[i];
			li = i;
		}
	}
	return li;
}
void CapNhatDuongDi(int u, DOTHI g)
{
	ChuaXet[u] = 1;
	for(int v = 0; v < g.n; v++)
	{
		if(ChuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC)
			if(DoDaiDuongDiToi[v] > DoDaiDuongDiToi[u] + g.a[u][v])
			{

					DoDaiDuongDiToi[v] = DoDaiDuongDiToi[u] + g.a[u][v];
					LuuVet[v] = u;
			}
	}
}
void Dijkstra(int S, int F, DOTHI g)
{
	int i;
	int nT = 0;
	int x[MAX];
	for(i = 0; i < g.n; i++)
	{
		ChuaXet[i] = 0;
		DoDaiDuongDiToi[i] = VOCUC;
		LuuVet[i] = -1;
	}
	DoDaiDuongDiToi[S] = 0;
	while(ChuaXet[F] == 0)
	{
		int u = TimDuongDiNhoNhat(g);
		if(u == -1)
			break;
		CapNhatDuongDi(u,g);
	}
	if(ChuaXet[F] == 1)
	{
		printf("Duong di ngan nhat tu dinh %c den dinh %c la:  ",S + 'A',F + 'A');
		i = F;
		x[nT] = F;
		while(LuuVet[i] != S)
		{
			nT++;
			x[nT] = LuuVet[i];
			i = LuuVet[i];
		}
		x[nT+1] = LuuVet[i];
		printf("%c ",x[nT+1] + 'A');
		for(i = nT; i >= 0; i--)
			printf("-> %c ",x[i] + 'A');
		printf("\nVoi do dai la %d\n", DoDaiDuongDiToi[F]);
	}
	else
		printf("Khong co duong di tu dinh %c den dinh %c\n",S + 'A', F + 'A');
}
int main()
{
	DOTHI g;                         
	if(DocFile(inputfile,g) == 1)    
	{	                                
 		printf("Da lay thong tin do thi tu file thanh cong. \n\n");
 		XuatMaTranKe(g);             
 		Dijkstra(0,4,g);
	}                                
 	else                             
 		printf("Doc file that bai.");
 	getch();
}

