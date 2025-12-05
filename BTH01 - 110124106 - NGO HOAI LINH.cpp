#include <stdio.h>

int A[101][101], n;

void readFile() {
	FILE *f;
	f=fopen("Matrix.txt", "r");
	if(f==NULL) printf("Loi mo file!!!!");
	else {
		fscanf(f, "%d", &n);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				fscanf(f, "%d", &A[i][j]);
	}
	fclose(f);
}

void inFile(){
	printf("So dinh: %d  \n", n);
	printf("Ma Tran Ke Vua Doc: \n");
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

int DoiXung (int A[][101], int n){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(A[i][j]!=A[j][i])
				return 0; //function tra ve 0 neu ma tran khong dx
	return 1; //tra ve 1 neu ma tran dx qua duong cheo chinh
}
int DuongCheo(int A[][101], int n){
	for(int i=1; i<=n; i++)
		if(A[i][i]!=0)
			return 0; //function tra ve 0 neu tren duong cheo co ptu khac 0
	return 1; //tra ve 1 neu duong cheo chi co ptu = 0
}
int GiaTri(int A[][101], int n){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(A[i][j]>1)
				return 0; //function tra ve 0 neu co bat ky ptu nao >1
	return 1; //tra ve 1 neu toan bo ptu deu nho hon bang 1
}
int main() {
	readFile();
	inFile();
	
	printf("\nTen: ");
	if(!DoiXung(A,n)) {
		if(GiaTri(A,n)) printf("\nDon Do Thi Co Huong"); //ma tran khong dx va gia tri ptu <= 1
		else printf("\nDa Do Thi Co Huong"); //ma tran khong dx co gia tri ptu >1
	}
	else {
		if(!DuongCheo(A,n))
			printf("\nGia Do Thi"); //ma tran dx co duong cheo khac 0
		else {
			if(GiaTri(A,n))
				printf("\nDon Do Thi Vo Huong"); //ma tran dx co duong cheo =0 va gia tri <=1
			else printf("\nDa Do Thi Vo Huong"); //ma tran dx co duong cheo =0 va gia tri >1
		}
	}
	return 0;
}

