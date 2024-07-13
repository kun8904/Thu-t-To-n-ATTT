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

// hàm kiểm tra nguyên tố cùng nhau
int gcd(int a, int b){
	while(b != 0){
        int temp = a % b;
        a = b; 
		b = temp;
    }
    return a;
}

int main() {
    long long n,check=0,tong=0;
    do {
        cout << "Nhap n: ";
        cin >> n;
    }while(n <= 0 || n >= 10000);
	
    for(int i = 2; i <= n; ++i){ //vòng lặp kiểm tra từng giá trị
        if(!check_snt(i)){
        	bool isCarmichael = true;
            for(int a = 2; a < i; ++a){
                if(gcd(a, i)==1){
                    long long r;
                    mod_bai(i, a, i - 1, r);
                    if(r != 1){
                        isCarmichael = false;
                        break;
                    }
                }
            }
            if(isCarmichael){
                tong+=i;
                check++;
            }
        }
    }
	if(check==0){
		cout << "Khong ton tai so Carmichae!" << endl;
	}else{
		cout << "tong cac so Carmichael la: "<< tong << endl;
	}

    return 0;
}
