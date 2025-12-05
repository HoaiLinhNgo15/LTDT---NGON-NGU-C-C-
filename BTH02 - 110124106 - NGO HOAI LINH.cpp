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

//KIEM TRA TINH DOI XUNG CUA MA TRAN
int DoiXung (){
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(A[i][j]!=A[j][i])
				return 0; //function tra ve 0 neu ma tran khong dx
	return 1; //tra ve 1 neu ma tran dx qua duong cheo chinh
}

//HAM MAIN
int main() {
	readFile();
	inFile();
	
	int x;
	printf("\nNhap dinh can tinh Bac: ");
	scanf("%d", &x);
	if(DoiXung()) { //tinh bac cua dinh x trong ma tran vo huong
		int bac=0;
		for(int i=1; i<=n; i++){
			if(i==x){
				if(A[x][i]>0)
					bac+=2*A[x][i];
			}
			else
				bac+=A[x][i];
		}
		printf("\nBac dinh %d la: %d", x, bac);
	}
	else { //ma tran co huong
		int Bacvao = 0, //Bacvao A[i][x]
			Bacra = 0; //Bacra A[x][j]
		for(int i=1; i<=n; i++) {
			Bacvao +=A[i][x];
			Bacra +=A[x][i];
		}
		printf("\nBac vao %d la: %d", x, Bacvao);
		printf("\nBac ra %d la: %d", x, Bacra);
	}
	return 0;
}

