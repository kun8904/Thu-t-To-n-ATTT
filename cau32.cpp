#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>
#include <gmpxx.h>
using namespace std;

// thuật toán kiểm tra số nguyên tố
bool check_snt(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i<=n; i++){
        if (n%i == 0) return false;
    }
    return true;
}

//hàm random giá trị
int findPrimeInRange(int start, int end){
    vector<int> primes;
    for(int i = start; i<=end; ++i){
        if(check_snt(i)){
            primes.push_back(i);
        }
    }
    if(primes.empty()) return -1;
    return primes[rand() % primes.size()];
}

//hàm gcd tìm ƯCLN
int gcd(int a, int b){
	while(b != 0){
        int temp = a % b;
        a = b; 
		b = temp;
    }
    return a;
}

//hàm tính giá trị nghịch đảo theo a^-1 mod p (thuật toán nghịch đảo)
int nghich_dao(int p , int a){
	int u, v, x1, x2, q, r, x;
	u = a;
	v = p;
	x1= 1;
	x2= 0;
	do{
		q = v/u;
		r = v - q*u;
		x = x2-q*x1;
		v = u;
		u = r;
		x2 = x1;
		x1 = x;
	}while(u!=1);
	if(x1<0){
		do{
			x1 += p ;
		}while(x1<0);
	}
	return x1;
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
	srand(time(0));
	long long m;
	//random 2 giá trị p và q
	int p = findPrimeInRange(101,499);
	int q = findPrimeInRange(101,499);
	int e,d,sbd;
	while(q==p){
        q = findPrimeInRange(101, 499);
    }
	
	int n = q*p;
	int f_n = (p-1)*(q-1);
	int i=2;
	//khởi tạo e với e nguyên tố cùng nhau với f_n
	do{
		e = i;
		i++;
	}while(gcd(e,f_n)!=1 and i<=f_n);
	d = nghich_dao(f_n,e);
	
	do{
		cout << "Nhap SBD sv: "; cin >> sbd;
	}while(sbd<=0);
	m = sbd+123;
	// bảng mã của thông điệp m
	long long c =0;
	mod_bai(n,m,e,c);
	mod_bai(n,c,d,m);
	cout << "Ban ma c: " << c << endl;
	cout << "Thong diep m: " << m << endl;
	
}