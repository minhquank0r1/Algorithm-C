//Đồ Thị Vô Hướng
#include <stdio.h>
#include <conio.h>
#define MAX 10
#define inputfile "Graph.txt"
typedef struct GRAPH{
	int n;
	int a[MAX][MAX];
}G;

int DocMaTranKe(char TenFile[100],G &g){
	FILE *f;
	f = fopen(TenFile,"rt");
	if(f==NULL){
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0; i < g.n; i++){
		for(int j =0; j < g.n; j++){
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void XuatMaTranKe(G g){
	printf("So dinh cua ma tran la: %d\n",g.n);
	printf("Ma tran ke cua do thi la\n");
	for(int i = 0; i < g.n; i++){
		for(int j = 0; j < g.n; j++){
			printf("%3d",g.a[i][j]);
		}
		printf("\n");
	}
}
int KiemTraMaTranKeHopLe(G g){
	int i;
	for(int i =0; i <g.n;i++){
		if(g.a[i][i] != 0){
			return 0;
		}
	}
	return 1;
}
int KiemTraDoThiVoHuong(G g){
	for(int i = 0; i <g.n;i++){
		for(int j = 0; j < g.n; j++){
			if(g.a[i][j] != g.a[j][i]){
				return 0;
			}
		}
	}
	return 1;
}
int main(){
	G g;
	if(DocMaTranKe(inputfile,g)==1){
		printf("Da lay thong tin thanh cong");
		XuatMaTranKe(g);
		if(KiemTraMaTranKeHopLe(g)==1){
			printf("Do thi hop le\n");
		}
		else{
			printf("Do thi khong hop le\n");
		}
		if(KiemTraDoThiVoHuong(g)==1){
			printf("Do thi vo huong\n");
		}
		else{
			printf("Do thi co huong\n");
		}
	}
	else{
		printf("Sai ten thu muc");
	}
	getch();
}
