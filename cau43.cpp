#include <iostream>
#include <gmpxx.h>
#include <vector>
#include <math.h>
using namespace std;

// kiểm tra số nguyên tố
bool check_snt(int a){ 
	if(a<=1) return false;
	if(a<=3) return true;
	if(a%2==0 or a%3==0) return false;
	for(int i=5; i*i<=a; i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

//thuật toán nhân bình phương có lặp
void mod_bai(long long n,long long a,long long k, long long &b){
	b=1;	
	if(k==0){
		b = 1;
	}else{
		vector<long long> X(0);
		int i=0;
		do{
			X.resize(i+1);
			X[i] = k%2;
			k = k/2;
			i++;
		}while(k!=0);
		if(X[0]==1){
			b = a;
		}
		i=1;
		do{
			a = a*a;
			if(a>n){
				do{
					a = a-n;
				}while(a>=n);
			}
			if(X[i]==1){
				b = a*b;
				if(b>n){
					do{
						b = b-n;
					}while(b>=n);
				}
			}
			i++;
		}while(i<=X.size()-1);		
	}
}

int main(){
	long long n,p;
	cout << "Nhap n thoa man 0<n<1000" << endl;
	do{
		cout << "Nhap n: "; cin >> n;
	}while(n<=0 or n>=1000);
	cout << "Nhap cac so voi dkien p<100 tinh a^p mod n" << endl;
	do{
		cout << "Nhap p: "; cin >> p;
	}while(p>=100);
	cout << "Danh sach cac so a thoa man: "; 
	for(int i=1; i<n; i++){
		long long kq;
		mod_bai(n,i,p,kq);
		if(check_snt(kq)){
			cout << i << " ";
		}
	}
}