#include <iostream>
#include <gmpxx.h>
#include <vector>
#include <math.h>
using namespace std;

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
	long long n,t,n_1,s=0,r=0,y,j,check,tmp;
	cout << "Kiem tra so nguyen to!" << endl;
	do{
		cout << "Nhap n la so nguyen le(n>=3): " ; cin >> n;
	}while(n<=3 or n%2==0);
	do{
		cout << "Nhap t(so lan lap): " ; cin >> t;
	}while(t<1);
	
	check=0;
	n_1 = n-1;
	do{
		n_1 = n_1/2;
		s++;
	}while(n_1%2!=1);
	r = n_1;
	for(int i=1; i<=t; i++){
		mod_bai(n,3,r,y);
		if(y!=n-1 and y!=1){
				j=1;
			while(j<=s-1 and y!=n-1){
				y = y*y;
				if(y>=n){
					do{
						y = y-n;
					}while(y>=n);
				}
				if(y==1){
					check++;
				}
				j++;
			}
			if(y!=n-1){
				check++;
			}	
		}
		if((check==0 && y==1) or (check==0 && y==n-1)){
			cout << n <<" la so nguyen to" << endl;
		}else{
			cout << n <<" la so hop so" << endl;
		}
	}
}