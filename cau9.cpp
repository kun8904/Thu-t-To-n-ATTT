#include <iostream>
#include <math.h>
using namespace std;

// thuật toán kiểm tra songto
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
	int n,tong = 0;
	do{
		cout << "Nhap n:" ; cin >> n;
	}while(n<=0);
	
    for(int i = 1; i < n; i++){
        if(check_snt(i)) tong++;
    }
	cout << "So luong cac so ngto <=" << n << " la: " << tong<< endl;
}
