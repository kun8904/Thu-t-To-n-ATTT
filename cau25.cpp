#include <iostream>
#include <vector>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i<=n; i ++){
        if (n%i == 0 	) return false;
    }
    return true;
}

// hàm đệ quy
bool findPrimeSum(int N, int M, vector<int>& result, const vector<int>& primes, int start){
    if(M == 0){
        return N == 0;
    }
    for(int i = start; i<primes.size(); i++){
        if(primes[i] <= N){
            result.push_back(primes[i]);
            if(findPrimeSum(N - primes[i], M - 1, result, primes, i + 1)){
                return true;
            }
            result.pop_back();
        }
    }
    return false;
}

int main(){
	int n,m,dem;
	vector<int> X(0); // vector chứa số nto
	vector<int> print(0);
	do{
		cout << "Nhap N: "; cin >> n;
	}while(n<1 or n>10000);
	
	do{
		cout << "Nhap M: "; cin >> m;
	}while(m<=2 or m>100);
	
	for(int i=1; i<=n; i++){
		if(isPrime(i)){
			X.push_back(i);
		}
	}
	
	if(findPrimeSum(n,m,print,X,0)){
        cout << "N co the duoc phan tich thanh tong cua " << m << " so nguyen to: ";
        for(int prime : print){
            cout << prime << " ";
        }
        cout << endl;
    }else{
        cout << "Khong the phan tich N thanh tong cua " << m << " so nguyen to." <<endl;
    }

    return 0;
}
