#include <iostream>
#include <math.h>

using namespace std;

bool check_snt(int a){
    if(a<=1) return false;
    if(a<=3) return true;
    if(a%2 == 0 || a%3 == 0) return false;
    for(int i=5;i*i<=a;i++){
    	if(a % i == 0 ) return false;
	}
	return true;
}

int main(){
	int n; 
	cout << "Nhap n:";
	cin >> n;
	for(int i=1; i<=n-2; i++){
		if(check_snt(i) and check_snt(i+2)){
			cout << i <<" " << i+2 << endl;
		}
	}
}