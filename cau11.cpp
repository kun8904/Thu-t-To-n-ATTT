#include <iostream>

using namespace std;
int main(){
	int n,check;
	int tong=0;
	cout << "Nhap n: " ; cin >> n;
	for(int i=1; i<=n; i++){
		check=0;
		if(i==2 or i==3){
			tong +=i;
		}else if(i>3){
			for(int j=2; j<i; j++){
				if(i%j==0){
					check++;
				}
			}
		}
		if(check==0 and i>3){
			tong+=i;
		}
	}
	cout  <<"Tong: " << tong << endl;
}