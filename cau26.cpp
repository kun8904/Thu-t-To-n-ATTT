#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i<=n; i++){
        if (n%i == 0) return false;
    }
    return true;
}

int main(){
	int n;
	vector<int> X(1);
	X[0] = 1;
	do{
		cout << "Nhap n:" ; cin >> n;
	}while(n>=10000 or n<0);
	for(int i=2; i<=n; i++){
		int tmp = i;
		for(int j=2; j<=i; j++){
			if(isPrime(j)){
				if(tmp%(j*j)==0){
                    while(tmp % j == 0){
                        tmp /= j;
                    }
				}
			}
		}
		if(tmp == 1){
			X.push_back(i);
		}
	}
	cout << "Day so manh me la: " ;
	for(int i=0; i<X.size(); i++){
		cout << X[i] << " ";
	}
}