#include<stdio.h>
#include<conio.h>
#define MAX 100
#define inputfile "Floyd.txt"
#define VOCUC 1000
int Sau_Nut[MAX][MAX];
int L[MAX][MAX];
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

void Floyd(DOTHI g)
{
	int i, j;
	for(i = 0;i<g.n;i++)
	{
		for(j = 0;j<g.n;j++)
		{
			if(g.a[i][j] > 0)
			{
				Sau_Nut[i][j] = j;
				L[i][j] = g.a[i][j];
			}
			else
			{
				Sau_Nut[i][j] = -1;
				L[i][j] = VOCUC;
			}
		}
	}
	for(int k = 0;k<g.n;k++)
	{
		for(i = 0;i<g.n;i++)
		{
			for(j = 0;j<g.n;j++)
			{
				if(L[i][j] > L[i][k] + L[k][j])
				{
					L[i][j] = L[i][k] + L[k][j];
					Sau_Nut[i][j] = Sau_Nut[i][k];
				}
			}
		}
	}
	int S,F;
	printf("nhap vao dinh bat dau: ");
	scanf("%d",&S);
	printf("Nhap vao dinh ket thuc: ");
	scanf("%d",&F);
	if(Sau_Nut[S][F] == -1)
	{
		printf("Khong co duong di tu dinh %d den dinh %d la:\n",S,F);
	}
	else
	{
		printf("Duong di ngan nhat tu dinh %d den dinh %d la :\n",S,F);
		printf("\t%c",S + 'A');
		int u = S;
		while(Sau_Nut[u][F] != F)
		{
			u = Sau_Nut[u][F];
			printf("--> %c",u + 'A');
		}
		printf(" --> %c",F+ 'A');
		printf("\n\tVoi tong trong so la %d",L[S][F]);
	}
}
int main()
{
	DOTHI g;
	if(DocFile(inputfile,g) == 1)
	{
		printf("Doc ma tran thanh cong.");
		XuatMaTranKe(g);
		Floyd(g);
	}
	else
	{
		printf("Doc that bai.");
	}
	getch();
	return 0;
}


