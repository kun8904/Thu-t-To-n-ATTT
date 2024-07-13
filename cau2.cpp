#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int x=0;
	long long n ;
	cout << "Nhap n: ";
	do{
		cin >> n;
	}while(n<2 or n>10);
	for(int i= pow(10,n-1); i<pow(10,n); i++){
		for(int j=2; j<=sqrt(i); j++){
			if(i%j==0){
				x++;
			}
		}
		if(x==0){
			cout << i << " ";
		}
		x=0;
	}
	return 0;
}