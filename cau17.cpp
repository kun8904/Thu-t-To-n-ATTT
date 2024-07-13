#include <iostream>
#include <math.h>
#include <gmpxx.h>
using namespace std;

bool check(long long a){
	if(a<=1) return false;
	if(a<=3) return true;
	if(a%2==0 or a%3==0) return false;
	for(int i=5; i*i<=a; i++){
		if(a%i==0) return false;
	}
	return true;
}

int main(){
	long long a,b,c,n;
	cout << "Nhap a,b,c: " ; cin >> a >> b >> c;
	cout << "nhap n: " ; cin >> n;
	cout << "Cac so nguyend uong x thoa man: ";
	for(int x=1; x<=n; x++){
		if(check(a*pow(x,2)+x*b+c)){
			cout << x << endl;
		}
	}
}