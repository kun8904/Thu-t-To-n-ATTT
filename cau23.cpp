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
	int a,b,tong=0;
	cout << "Nhap a va b: " ; cin >> a >> b;
	if(a>=b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	for(int i=a; i<=b; i++){
		tong += i;
	}
	if(check_snt(tong)){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}