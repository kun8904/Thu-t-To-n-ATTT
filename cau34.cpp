#include <iostream>
#include <vector>
#include <gmpxx.h>
using namespace std;

// hàm tính a^k mod n
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
				}while(a>=n); // xử lí a mod n
			}
			if(X[i]==1){
				b = a*b;
				if(b>n){
					do{
						b = b-n;
					}while(b>=n); // xử lí b mod n
				}
			}
			i++;
		}while(i<=X.size()-1);		
	}
}

int main(){
	long long n,k,t;
	long long a,r;
	do{
		cout << "nhap n: ";cin >> n;
		cout << "nhap t(so lan lap): ";cin >> t;
	}while(n<3 or n%2!=1 or t<1);
	do{
		cout << "nhap a: "; cin >> a;
	}while(a<2 or a>n-2);
	for(int i=1; i<=t; i++){
		mod_bai(n,a,n-1,r);	
	}
	if(r!=1){
		cout << "Hop so" << endl;
	}else{
			cout << "nguyen to" << endl; 
	}
}