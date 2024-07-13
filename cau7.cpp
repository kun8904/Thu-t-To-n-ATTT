#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void check_snt(vector<int>& X, int n,int &dem){
	int check,x=2;
	for(int i=2; i<=n; i++){
		if(i==2 or i==3){
			X[0] = 2;
			X[1] = 3;
			dem++;
		}else if(i>3){
			for(int j=2; j<=sqrt(n); j++){
				if(i%j==0){
					check++;
				}
			}
		}
		if(check==0 and i>3){
			X[x] = i;
			dem++;
			x++;
		}
		check=0;
	}
}

int main(){
	int n,dem=0,dem1=0,check,tmp;
	int result;
	cout << "Nhap so n: " ; cin >> n;
	vector<int> X(n);
	
	//hàm tìm số nguyên tố 
	check_snt(X,n,dem); //vector gồm các số nto chưa đảo ngược
	vector<int> Y(dem); //vector gồm các số nto đảo ngược
	X.resize(dem);
	
	//Hàm đảo ngược số
	for(int i=0; i<dem; i++){
		result = 0;
		tmp = X[i];
		do{
			result = result*10 + tmp%10;
			tmp = tmp/10;
		}while(tmp!=0);
		Y[i] = result;
	}
	
	for(int i=0; i<dem; i++){
		check=0;
		for(int j=2; j<=sqrt(dem); j++){
			if(Y[i]%j==0){
				check++;
			}
		}
		if(check==0){
			cout << X[i] << " ";
		}
	}
	return 0;
}

//ý tưởng: lập vector gồm các số ngto chưaa đảo ngược sau đó đảo ngược tại từng vị trí và ktr lại r in ra