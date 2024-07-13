#include <iostream>
#include <vector>
#include <gmpxx.h>
using namespace std;

// thuật toán kiểm tra hợp số
bool check_snt(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i<=n; i++){
        if (n%i == 0) return false;
    }
    return true;
}

//thuật toán nhân bình phương có lặp
void mod_bai(long long n,long long a,long long k,long long &b){
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
		}while(k!=0); // hàm xử lí số mũ
		
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

//hàm kiểm tra số nto gần nhất
int check_snt_gan(long long m){
	int truoc_msv = m;
	int sau_msv = m;
	
	while(!check_snt(truoc_msv)){
		truoc_msv--;
	}
	while(!check_snt(sau_msv)){
		sau_msv++;
	}
	
	if((m-truoc_msv)<=(sau_msv-m)){
		return truoc_msv;
	}else{
		return sau_msv;
	}
}


int main() {
    long long msv=190523,k,a,b=0;
    k = check_snt_gan(msv);
    do{
    	cout << "Nhap SBD:"; cin >> a;
	}while(a<=0);
	mod_bai(123456,a,k,b);
	cout << "Ket qua cua bai toan: " << b << endl;
    return 0;
}
