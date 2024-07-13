#include <iostream>

using namespace std;

bool check_snt(int a){
	if(a<=1) return false;
	if(a<=3) return true;
	if(a%2==0 || a%3==0) return false;
	for(int i=5; i*i<=a; i++){
		if(a%i==0 || a%(i+2)==0) return false;
	}
	return true;
}

int main(){
	int m,l,a,b,c,tong;
	do{
		cout << "Nhap m:" ; cin >> m;
		cout << "Nhap l:" ; cin >> l;
	}while(m>=l);
	cout << "Nhap a, b, c: "; cin >> a >> b >> c;
	cout << "Day so can tim: ";
	for(int i=m; i<=l; i++){
		tong = a*i*i+b*i+c;
		if(check_snt(tong)){
			cout << i << " " ;
		}
	}
	 
}