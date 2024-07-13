#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int a,b;
	int check=0;
	int tong =0;
	cout <<"Nhap so tu nhien a,b: " << endl;
	cout <<"a = " ; cin >> a;
	cout <<"b = " ; cin >> b;
	
	//hàm tìm số nguyên tố
	for(int i=a; i<=b; i++){
		if(i==2 or i==3){
			tong +=i;
		}else if(i>1){
			for(int j=2; j<=sqrt(i); j++){
				if(i%j==0){
					check++;
				}
			}
			if(check==0){
				tong += i;
			}
			check=0;
		}
	}
	cout << "Tong cac so nguyen to tu [" <<a<<","<<b<< "] = "<< tong << endl;
	return 0;
}