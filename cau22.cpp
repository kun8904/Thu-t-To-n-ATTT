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
	int l,r,tong=0,a,b;
	cout << "Nhap l, r: " ; cin >> l >> r;
	if(l>r){
		int tmp = l;
		l = r ;
		r = tmp;
	}
	
    for(int i = l; i <= r; i++){
        if(check_snt(i)){
            for(int j =i+1; j<=r; j++){
                if(check_snt(j) and check_snt(i)){
                    tong += i * j;
                }
            }
        }
    }
	cout << tong << endl;
}