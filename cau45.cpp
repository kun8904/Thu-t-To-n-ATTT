#include <iostream>
#include <vector>
#include <ctime>
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

long long min_Array(const vector<long long> primes){
    long long min_a= abs(primes[0] - primes[1]);
    for(int i=0; i<primes.size(); i++){
    	for(int j=i+1; i<primes.size(); i++){
            min_a = abs(min(min_a, primes[i] - primes[j]));		
		}
    }
    return min_a;
}

int main(){
	long long n, t, n_1, s=0, r=0, y, j, check, tmp, random;
	cout << "Nhap N phan tu nguyen to!!!" << endl;
	do{
		cout << "Nhap n: " ; cin >> n;
	}while(n<=0);
	vector<long long> A,B;
	t = 5; // số lần lặp cho thuật toán
	int i = 0;

	srand(time(0));
	do{
  		long long random = rand();
		int u = random;
		check=0;
		if(u%2==1){
			n_1 = u-1; 
			do{
				n_1 = n_1/2;
				s++;
			}while(n_1%2!=1);
			r = n_1;
			
			for(int i=1; i<=t; i++){
				mod_bai(u,3,r,y); // kiểm tra 
				if(y!=n-1 and y!=1){
					j=1;
					while(j<=s-1 and y!=u-1){
						y = y*y;
						if(y>=u){
							do{
								y = y-u;
							}while(y>=u);
						}
						if(y==1){
							check++;
						}
						j++;
					}
					
					if(y!=u-1){
						check++;
					}	
				}
			}
			if((check==0 && y==1) or (check==0 && y==u-1)){
				A.push_back(random);
        		i++;
			}
		}
	}while(i<=n);
	
	if(n==1){
		cout << "\nKhong ton tai khoang cach be nhat giua 2 so ngto bat kia!!!" << endl;
	}else{
		cout << "Mang cac so nguyen to duoc random : ";
		for(int i=0; i<n; i++){
			cout << A[i] << " " ;
		}
		cout << endl;
		cout << "Khoang cach be nhat cua 2 so nguyen to trong mang: ";
		cout << min_Array(A) << endl;
	}
}