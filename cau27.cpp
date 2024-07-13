#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool check_snt(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i<=n; i++){
        if (n%i == 0) return false;
    }
    return true;
}

int main(){
	int a, b, gcd;
	for(a=1; a<=1000; a++){
		for(b=a; b<=1000; b++){
			for(int i=1; i<=1000; i++){
				if(b%i==0 && a%i==0){
					gcd = i;
				}
			}
			if(check_snt(gcd)){
				cout << a <<" " << b << endl;
			}
		}
	}
}