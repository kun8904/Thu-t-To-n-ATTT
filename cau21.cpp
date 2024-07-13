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
	int a,b,dem,dem_snt=0;
	cout <<"Nhap a,b:"; cin >> a >> b;
	if(a>b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	
	for(int i=a; i<=b; i++){
		dem=0;
		for(int j=1; j<i; j++){
			if(check_snt(j)){
				dem++;
			}
		}
		if(check_snt(dem)){
			cout << i <<" "<< dem<< endl;
			dem_snt++;
		}
	}
	cout << dem_snt<< endl;
}