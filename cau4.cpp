#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int a,b;
	int check=0;
	cout <<"Nhap so tu nhien a,b: "; cin >> a ; cin >> b;
	cout <<"Day so nguyen to doan [A,B] la: " << endl;
	
	//hàm tìm số nguyên tố
	for(int i=a; i<=b; i++){
		if(i==2 or i==3){
			cout << i << " ";
		}else if(i>1){
			for(int j=2; j<=sqrt(i); j++){
				if(i%j==0){
					check++;
				}
			}
			if(check==0){
				cout << i << " ";
			}
			check=0;
		}
	}
	return 0;
}