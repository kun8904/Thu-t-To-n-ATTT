#include <iostream>

using namespace std;

int gcd(int a, int b){ // b>=a
	int tmp;
	for(int i=1; i<=a; i++){
		if(a%i==0 and b%i==0){
			tmp = i;
		}
	}
	return tmp;
}

int main(){
	int m,n,d;
	do{
		cout << "Nhap m, n, d: " ; cin >> m >> n >> d;
	}while(m<0 or m >1000 or n<0 or n>1000 );
	if(m>n){
		int tmp = m;
		m = n;
		n = tmp;
	}
	
	for(int i=m; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(gcd(i,j)==d){
				cout << i << " " << j << endl;
			}
		}
	}
}