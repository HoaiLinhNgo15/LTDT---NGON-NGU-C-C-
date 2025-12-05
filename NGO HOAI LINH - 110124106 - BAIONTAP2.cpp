#include <bits/stdc++.h>
#define M 101
using namespace std;

//tim phan tu nho nhat tren cot y
void inMin(int A[][M], int n, int y) {
	int min =A[1][y];
	for(int i=2; i<=n; i++)
		if(A[i][y] < min)
			min=A[i][y];
	cout << endl << "Phan tu nho nhat tren cot " << y <<" la: " << min << endl;
}

//tong cac phan tu tren hang k
int sumRow(int A[][M], int n, int k) {
	int sum=0;
	for(int i=1; i<=n; i++)
		sum+=A[k][i];
	return sum;
}

//tong phan tu tren cot m
int sumColum(int A[][M], int n, int m) {
	int sum=0;
	for(int i=1; i<=n; i++)
		sum+=A[i][m];
	return sum;
}

//tong tat ca cac ptu trong ma tran
int sumMatrix(int A[][M], int n){
	int sum=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			sum+=A[i][j];
	return sum;
}

//tong ptu va ptu tren duong cheo nhan 2
int sumMatrix1(int A[][M], int n){
	int sum=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			if(i==j)
				sum+=2*A[i][j];
			else sum+=A[i][j];
		}
	return sum;
}

//tong ptu chan
int sumMatrix2(int A[][M], int n){
	int sum=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			if(A[i][j]%2==0)
				sum+=A[i][j];
		}
	return sum;
}

//tong nua tren duong cheo
int sumMatrix3(int A[][M], int n){
	int sum=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			if(i<j)
				sum+=A[i][j];
				
		}
	return sum;
}

// kiem tra duong cheo bang 0
int checkMatrix(int A[][M], int n){ 
	if(n==0)
		return 1;
	if(n==1)
		if(A[1][1]==0)
			return 1;
		else return 0;
	int found=0;
	for(int i=1; i<=n; i++){
		if(A[i][i]==0)
			found++;
	}
	if(found<n)
		return 0;
	return 1;
}

//kiem tra ptu co nho hon bang 1
int checkMatrix1(int A[][M], int n){ 
	if(n==0)
		return 1;
	if(n==1)
		if(A[1][1]>1)
			return 0;
		else return 1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(A[i][j] >1)
				return 0;
	return 1;
}

//kiem tra ma tran co doi xung qua duong cheo chinh hay khong
int checkMatrix2(int A[][M], int n){
	if(n<=1 )
		return 1;
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++)
			if(A[i][j]!=A[j][i])
				return 0;
	return 1;
}

//ham main
int main(){
	int n, A[M][M]; //n la kich thuoc ma tran
	cin >> n;
	
	//nhap gia tri vao ma tran vuong
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> A[i][j];
	//2.1
	int x,max;
	cin >> x;
	max=A[x][1];
	for(int i=2; i<=n; i++)
		if(A[x][i] > max)
			max=A[x][i];
	cout << endl << "Phan tu lon nhat tren hang " << x << " la: " << max << endl;
	
	//2.2
	int y; cin >> y;
	inMin(A,n,y);
	
	//2.3
	int k; cin >> k;
	cout << endl << "Tong cac phan tu tren hang " << k << " la: " << sumRow(A,n,k) << endl;
	
	//2.4
	int m; cin >> m;
	cout << endl << "Tong cac phan tu tren cot " << m << " la: " << sumColum(A,n,m) << endl;
	
	//2.5
	cout << endl << "Tong cac phan tu ma tran la: " << sumMatrix(A,n) << endl;

	//2.6
	cout << endl << "Tong cac phan tu ma tran co ptu duong cheo nhan doi la: " << sumMatrix1(A,n) << endl;
		
	//2.7
	 cout << endl << "Tong cac phan tu chan trong ma tran la: " << sumMatrix2(A,n) << endl;
	 
	//2.8
	cout << endl << "Tong cac phan tu phia tren duong cheo trong ma tran la: " << sumMatrix3(A,n) << endl;

	//2.9
	if(checkMatrix(A,n))
		cout << "Ma tran bang 0" << endl;
	else cout << "Ma tran khac 0" << endl;

	//2.10
	if(checkMatrix1(A,n))
		cout << "YES" << endl;
	else cout << "NO" << endl;

	//2.11
	if(checkMatrix2(A,n))
		cout << "DOI XUNG" << endl;
	else cout << "KHONG DOI XUNG" << endl;

	return 0;
}
