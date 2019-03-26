//Chu trình Euler
#include <stdio.h>
#include <conio.h>
#define MAX 100
#define inputfile "Euler.txt"
typedef struct Euler{
	int n;
	int a[MAX][MAX];	
	int bac[MAX];
}E;
struct STACK{
	int array[100];
	int size;
};
int DocMaTranKe(char TenFile[100],E &e){
	FILE *f;
	f = fopen(TenFile,"rt");
	if(f==NULL){
		printf("Khong mo duoc file");
		return 0;
	}
	fscanf(f,"%d",&e.n);
	for(int i = 0; i < e.n; i++){
		e.bac[i] = 0;
		for(int j = 0; j < e.n; j++){
			fscanf(f,"%d",&e.a[i][j]);
			e.bac[i]+=e.a[i][j];
		}
	}
	fclose(f);
	return 1;
}
void XuatMaTranKe(E e){
	printf("So dinh cua ma tran la %d\n",e.n);
	printf("Ma tran cua do thi la \n");
	for(int i = 0; i < e.n; i++){
		for(int j = 0 ; j < e.n; j++){
			printf("%3d",e.a[i][j]);
		}
		printf("\n");
	}
}
void KhoiTaoStack(STACK &stack){
	stack.size = 0;
}
void DayGiaTriVaoStack(STACK &stack, int value){
	if(stack.size + 1 >= 100){
		return;
	}
	stack.array[stack.size] = value;
	stack.size++;
}
void TimDuongDi(int i,E &e,STACK &stack){
	for(int j = 0; j < e.n; j++){
		if(e.a[i][j] != 0){
			e.a[i][j] = e.a[j][i] = 0;
			TimDuongDi(j,e,stack);
		}
	}
	DayGiaTriVaoStack(stack,i);
}
int TimDinhXuatPhat(E e){
	for(int i = 0; i<e.n;i++){
		if(e.bac[i]>0){
			return i;
		}
	}
	return -1;
}
int CoChuTrinhEuler(E e,STACK stack){
	if(stack.array[0] != stack.array[stack.size-1]){
		return 0;
	}
	for(int i = 0; i < e.n;i++){
		for(int j = 0; j< e.n;j++){
			if(e.a[i][j]>0){
				return 0;
			}
		}
	}
	return 1;
}

void XuatChuTrinhEuler(STACK stack){
	printf("\nXuat phat: %c",stack.array[stack.size-1]+'A');
	for(int i = stack.size-2;i>=0;i--){
		printf("-> %c",stack.array[i]+'A');
	}
}
int KiemTraChuTrinhEuler(E e){
	int i,j;
	int x = 0;
	x = TimDinhXuatPhat(e);
	E temp = e;
	STACK stack;
	KhoiTaoStack(stack);
	TimDuongDi(x,temp,stack);
	if(CoChuTrinhEuler(temp,stack)==1){
		printf("\nChu trinh Euler");
		XuatChuTrinhEuler(stack);
		return 1;
	}
	return 0;
}
int main(){
	E e;
	if(DocMaTranKe(inputfile,e)==1){
		XuatMaTranKe(e);
		if(KiemTraChuTrinhEuler(e)==0){
			printf("\nKhong co chu trinh Euler");
		}
	}
	getch();
}

