#include<stdio.h>
#include<conio.h>
#define MAX 100
#define inputfile "Euler.txt"
typedef struct GRAPH
{
	int n;
	int a[MAX][MAX];
	int bac[MAX];
}DOTHI;
int DocFile(char file[100], DOTHI &g)
{
	FILE *f;
	f = fopen(file,"rt");
	if(f == NULL)
	{
		printf("Khong mo duoc file.");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0; i < g.n; i++)
	{
		g.bac[i]=0;
		for(int j = 0; j < g.n; j++)
		{
			fscanf(f,"%d",&g.a[i][j]);
			g.bac[i]+=g.a[i][j];
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
struct STACK
{
	int array[100];
	int size;
};
void khoitaoSTACK(STACK &stack)
{
	stack.size = 0;
}
void DayGiaTriVaoStrack(STACK &stack, int value)
{
	if(stack.size + 1 >= 100)
		return;
	stack.array[stack.size] = value;
	stack.size++;
}
void TimDuongDi(int i, DOTHI &g, STACK &stack)
{
	DayGiaTriVaoStrack(stack,i);
	for(int j = 0; j < g.n; j++)
		if(g.a[i][j] != 0)
		{
			g.a[i][j] = g.a[j][i] = 0;//theo thuat toan fleury
			TimDuongDi(j,g,stack);
			
		}
}
int TimDinhXuatPhat(DOTHI g)
{
	for(int i=0;i<g.n; i++)
		if(g.bac[i]>0 )
			return i;
	return -1;//khong tim thay dinh nao, do thi nay khong noi voi nhau
}
int CoChuTrinhEuler(DOTHI g, STACK s)
{
	if(s.array[0] != s.array[s.size-1]) 
		return 0; 	//khong co chu trinh Euler
	for(int i=0;i< g.n; i++)
		for(int j=0;j<g.n; j++)
			if(g.a[i][j]>0)
				return 0; //khong co chu trinh Euler
	return 1; //co chu trinh Euler
}
void XuatChuTrinhEuler(STACK s)
{
	printf("\nXuat phat: %c", s.array[s.size-1] + 'A');
	for(int i = s.size-2; i >= 0; i--) //duyet nguoc
		printf(" -> %c", s.array[i] + 'A');
}
int KiemTraChuTrinhEuler(DOTHI g)
{
	int i,j;
	int x=0;
	x=TimDinhXuatPhat(g);
	DOTHI temp = g;
	STACK stack;
	khoitaoSTACK(stack);
	TimDuongDi(x,temp,stack);
	if(CoChuTrinhEuler(temp, stack)==1)
	{
		printf("\nChu trinh Euler: ");
		XuatChuTrinhEuler(stack);
		return 1;
	}
	return 0; //khong co chu trinh Euler
}
int TimDinhXuatPhatBacLe(DOTHI g)
{
	for(int i = 0; i < g.n; i++)
		if(g.bac[i] % 2 == 1 && g.bac[i] > 0)
			return i;
	return -1;
}
int CoDuongDiEuler(DOTHI g, STACK s)
{
	for(int i=0;i< g.n; i++)
		for(int j=0;j<g.n; j++)
			if(g.a[i][j]>0)
				return 0; //khong co chu trinh Euler
	return 1;
}
int KiemTraDuongDiEuler(DOTHI g)
{
	int i,j;
	int x=0;
	x=TimDinhXuatPhatBacLe(g);
	DOTHI temp = g;
	STACK stack;
	khoitaoSTACK(stack);
	TimDuongDi(x,temp,stack);
	if(CoDuongDiEuler(temp, stack)==1)
	{
		printf("\nDuong di Euler: ");
		XuatChuTrinhEuler(stack);		
		return 1;
	}
	return 0;
}
int main()
{
	DOTHI g;
	if(DocFile(inputfile,g)==1)
	{
		XuatMaTranKe(g);
		if(KiemTraDuongDiEuler(g)==0)
			printf("\nKhong co duong di Euler");
	}
	getch();
}

