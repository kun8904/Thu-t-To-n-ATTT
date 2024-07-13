#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	int check1=0,check2=0,check_snt;
	do{
		cout << "Nhap n:" ; cin >> n;
	}while(n<=0);
	
	for(int i=1; i<=n; i++){
		check_snt=0;
		if(n%i==0){
			check2++;
		}
		
		if(i==2 or i==3){
			check1++;
		}else{
			for(int j=2; j<i; j++){
				if(i%j==0){
					check_snt++;
				}
			}
		}
		
		if(check_snt==0 and i>3){
			check1++;
		}
	}
	cout << "So luong cac so ngto <" << n << " la: " << check1<< endl;
	cout << "So luong uoc cua " << n << " la: " << check2<< endl;
}