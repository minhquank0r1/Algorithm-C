#include<stdio.h>
#include<conio.h>
#define MAX 20
#define inputfile "Kruskal.txt"
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
typedef struct EDGE
{
	int u;
	int v;
	int value;
}CANH;
void SapXepTang(CANH E[100], int tongsocanh)
{
	CANH tam;
	for(int i = 0; i < tongsocanh - 1; i++)
	{
		for(int j = i + 1; j < tongsocanh; j++)
		{
			if(E[i].value > E[j].value  )
			{
					tam = E[i];
					E[i] = E[j];
					E[j] = tam;
					continue;
			}
			if(E[i].value == E[j].value && E[i].u > E[j].u)
			{
					tam = E[i];
					E[i] = E[j];
					E[j] = tam;
					continue;	
			}
			if(E[i].value == E[j].value && E[i].u == E[j].u && E[i].v > E[j].v)
			{
					tam = E[i];
					E[i] = E[j];
					E[j] = tam;	
			}
		}
			
	}
}
void Kruskal(DOTHI g)
{
	CANH list[MAX];
	int tongsocanh = 0;
	int i, j;
	for(i = 0; i < g.n; i++)
		for(j = i+1; j < g.n; j++)
			if(g.a[i][j] > 0)
			{
				list[tongsocanh].u = i;
				list[tongsocanh].v = j;
				list[tongsocanh].value = g.a[i][j];
				tongsocanh++;
			}
	SapXepTang(list,tongsocanh);
	int nT = 0;
	CANH T[MAX];
	int nhan[MAX];
	for(i = 0; i < g.n; i++)
		nhan[i] = i;
	int canhdangxet = 0;
	for(int i = 0; i < tongsocanh; i ++)
	{
		printf("\n %c %c %d",list[i].u + 'A',list[i].v + 'A', list[i].value);
	}
	while(nT < g.n && canhdangxet < tongsocanh)
	{
		if(nhan[list[canhdangxet].u] != nhan[list[canhdangxet].v])
		{
			T[nT] = list[canhdangxet];
			nT++;
			int giatri = nhan[list[canhdangxet].v];
			for(j = 0; j < g.n; j++)
				if(nhan[j] == giatri)
					nhan[j] = nhan[list[canhdangxet].u];
		}
		canhdangxet++;
	}
	if(nT != g.n - 1)
		printf("\nDo thi khong lien thong \n");
	else
	{
		int TongTrongSoCuaCayKhung = 0;
		printf("\nDo thi lien thong");
		printf("Cay khung nho nhat cua do thi la \n");
		for(i = 0; i < nT; i++)
		{
			printf("(%c,%c), ",T[i].u + 'A', T[i].v + 'A');
			TongTrongSoCuaCayKhung += T[i].value;
		}
		printf("\nTong gia tri cua cay khung la %d\n",TongTrongSoCuaCayKhung);
	}
}
int main()
{
	DOTHI g;                         \
	if(DocFile(inputfile,g) == 1)    
	{	                                
 		printf("Da lay thong tin do thi tu file thanh cong. \n\n");
 		XuatMaTranKe(g);             
 		Kruskal(g);
	}                                
 	else                             
 		printf("Doc file that bai.");
 	getch();
}

