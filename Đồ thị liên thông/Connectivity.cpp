//Đồ Thị Vô Hướng
#include <stdio.h>
#include <conio.h>
#define MAX 10
#define inputfile "Connectivity.txt"
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}G;
int DocMaTranKe(char TenFile[100],G &g){
	FILE *f;
	f = fopen(TenFile,"rt");
	if(f==NULL){
		printf("Khong doc mo duoc file\n");
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0; i < g.n; i++){
		for(int j = 0 ; j < g.n; j++){
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void XuatMaTranKe(G g){
	printf("So dinh cua do thi la %d\n",g.n);
	printf("Ma tran ke cua do thi la\n");
	for(int i = 0; i < g.n; i++){
		for(int j = 0; j< g.n;j++){
			printf("%3d",g.a[i][j]);
		}
		printf("\n");
	}
}
void DiTimCacDinhLienThong(G g, int Nhan[MAX],int i){
	for(int j = 0; j <g.n;j++){
		if(g.a[i][j] != 0 && Nhan[j] != Nhan[i]){
			Nhan[j] = Nhan[i];
			DiTimCacDinhLienThong(g,Nhan,j);
		}
	}
}
void XetLienThong(G g){
	int Nhan[MAX];
	int i;
	for(i = 0; i < g.n; i++){
		Nhan[i] = 0;
	}
	int SoThanhPhanLT = 0;
	for(i = 0; i < g.n; i++){
		if(Nhan[i] == 0){
			SoThanhPhanLT++;
			Nhan[i] = SoThanhPhanLT;
			DiTimCacDinhLienThong(g,Nhan,i);
		}
	}
	printf("So thanh phan lien thong la %d\n",SoThanhPhanLT);
	for(int i = 1; i <= SoThanhPhanLT; i++){
		printf("Thanh phan lien thong thu %d gom cac dinh",i);
		for(int j = 0; j <g.n;j++){
			if(Nhan[j]==i){
				printf("%3d",j);
			}
		}
		printf("\n");
	}
}

int main(){
	G g;
	if(DocMaTranKe(inputfile,g)==1){
		printf("Lay thong tin do thi thanh cong\n");
		XuatMaTranKe(g);
		XetLienThong(g);
	}
	else{
		printf("Khong doc duoc file");
	}
	getch();
}
