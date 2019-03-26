#include<stdio.h>
#include<conio.h>
#define MAX 100
#define inputfile "Prim.txt"

int ChuaXet[MAX];
typedef struct EDGE{
	int u;
	int v;
	int value;
}CANH;

CANH T[MAX];

typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}DoThi;

int DocMaTran(char TenFile[100],DoThi &g)
{
	FILE *f;
	f = fopen(TenFile,"rt");
	if(f == NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0 ; i<g.n;i++)
	{
		for(int j = 0;j<g.n;j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}

void XuatMaTran(DoThi g){
	printf("So dinh cua ma tran %d\n",g.n);
	for(int i = 0;i<g.n;i++)
	{
		for(int j = 0; j<g.n;j++)
		{
			printf("%4d",g.a[i][j]);
		}
		printf("\n");
	}
}

void DiTimDinhLienThong(DoThi g, int nhan[MAX], int i)
{
	for(int j = 0;j<g.n;j++)
	{
		if(g.a[i][j] != 0 && nhan[i] != nhan[j])
		{
			nhan[j] = nhan[i];
			DiTimDinhLienThong(g,nhan,j);
		}
	}
}

int XetLienThong(DoThi g)
{
	int Nhan[MAX];
	int i;
	for(i = 0;i<g.n;i++)
	{
		Nhan[i] = 0;
	}
	int SoThanhPhanLT = 0;
	for(i = 0;i<g.n;i++)
	{
		if(Nhan[i] == 0)
		{
			SoThanhPhanLT++;
			Nhan[i] = SoThanhPhanLT;
			DiTimDinhLienThong(g,Nhan,i);
		}
	}
	return SoThanhPhanLT;
}
void Prim(DoThi g)
{
	if(XetLienThong(g) != 1)
	{
		printf("Do thi khong lien thong, do do khong thuc hien duoc thuat toan prim cay khung nho nhat\n");
		return;
	}
	int nT = 0;
	for(int i = 0 ; i<g.n;i++)
	{
		ChuaXet[i] = 0;
	}
	ChuaXet[0] = 1;
	while(nT<g.n-1)
	{
		CANH CanhNhoNhat;
		int GiaTriNhoNhat = 100;
		for(int i = 0;i<g.n;i++)
		{
			if(ChuaXet[i] == 1)
			{
				for(int j = 0;j<g.n;j++)
				{
					if(ChuaXet[j] == 0 && g.a[i][j] != 0 && GiaTriNhoNhat > g.a[i][j])
					{
						CanhNhoNhat.u = i;
						CanhNhoNhat.v = j;
						CanhNhoNhat.value = g.a[i][j];
						GiaTriNhoNhat = g.a[i][j];
					}
				}
			}
		}
		T[nT] = CanhNhoNhat;
		nT++;
		ChuaXet[CanhNhoNhat.v] = 1;
	}	
	int TongTrongSoCuaCayKhung = 0;
	printf("Cay khung nho nhat cua do thi\n");
	for(int i = 0; i<nT-1;i++)
	{
		printf("(%d,%d),",T[i].u,T[i].v);
		TongTrongSoCuaCayKhung += T[i].value;
	}
	printf("(%d,%d).\n",T[nT - 1].u,T[nT-1].v);
	TongTrongSoCuaCayKhung += T[nT-1].value;
	printf("Tong gia tri cua cay khung la %d\n",TongTrongSoCuaCayKhung);
}

int main()
{
	DoThi g;
	if(DocMaTran(inputfile,g) == 1)
	{
		printf("Doc thong tin do thi thanh cong\n");
		XuatMaTran(g);
		Prim(g);
	}
	getch();
	return 0;
}

