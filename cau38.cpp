#include <iostream>
using namespace std;

int euclide(int a, int b){
	int d,x,y,q,r;
	if(b==0){
		return 0;
	}else{
		int x2=1, x1=0, y2=0, y1=1;
		do{
			q = a/b;
			r = a-q*b;
			x = x2-q*x1;
			y = y2-q*y1;
			a = b;
			b = r;
			x2 = x1;
			x1 = x;
			y2 = y1;
			y1 = y;
		}while(b>0);
		d = a;
		x = x2;
		y = y2;
		return x2;
	}
}

int gcd(int a, int b){
	if(a == 0 || b == 0){
        return a + b;
    }
    int tmp,check;
	if(a>=b){
		tmp = b;
	}else{
		tmp = a;
	}
	for(int i=1; i<=tmp; i++){
		if(a%i==0 and b%i==0){
			check = i;
		}
	}
	return check;
}

int main(){
	int a,b,r;
	cout << "Nhap 2 so a va p co UCLN = 1 va a<=p" << endl;
	do{
		cout << "Nhap a: "; cin >> a;
		cout << "Nhap p: "; cin >> b;
	}while(a<=0 or b<=0 or a%b==0 or a>=b);
	if(gcd(a,b)==1){
		r = euclide(a,b);
		cout <<"So nghich dao cua "<<a<<"^-1 = "<< r << endl;
	}else{
		cout << "UCLN cua 2 so khac 1" << endl;
	}
}