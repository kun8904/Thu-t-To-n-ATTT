#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n,x,check;
	cout << "Nhap n: " ; cin >> n;
	for(int i=1; i<=n; i++){
		check=0;
		for(int j=1; j<=i; j++){
			if(i%j==0){
				check++;
			}
		}
		if(check==3){
			cout << i << " " ;
		}
	}
}