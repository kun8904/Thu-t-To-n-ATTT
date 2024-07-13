#include <iostream>
#include <vector>
#include <gmpxx.h>
using namespace std;

int phep_nghich_dao(long long a,long long b){
	long long d,x,y;
	if(b==0){
		d = a;
		x = 1;
		y = 0;
		return x;
	}else{
		int x1=0, x2=1, y1=1,y2=0,q=0,r=0;
		do{
			{
				q = a/b;
				r = a-q*b;
				x = x2-x1*q;
				y = y2-y1*q;
			}
			
			{
				a = b;
				b = r;
				x2 = x1;
				x1 = x;
				y2 = y1;
				y1 = y;
			}
		}while(b>0);
		d = a;
		x = x2;
		y = y2;
		return x2;
	}
}

//search UCLN
int gcd(int a, int b){
	if(a<=0 or b<=0){
		return false;
	}
	int tmp,check;
	// đảo vị trí
	if(a>=b){
		tmp = b;
	}else{
		tmp = a;
	}
	
	// tìm UCLN
	for(int i=1; i<=tmp; i++){
		if(a%i==0 and b%i==0){
			check = i;
		}
	}
	return check;
}

int main(){
	long long a,p,n,k;
	label:
		cout << "Nhap truong Fp: " ; cin >> p;
		
		do{
			cout << "Nhap do dai cua day: "; cin >> n;	
		}while(n<=0);
		vector<int> A(n);
		
		for(int i=0; i<n; i++){
			int m;
			do{
				cout << "A[" << i+1 << "] = "; cin >> m;
			}while(m>=p or m<0);
			A[i]=m;
		}
		
		cout << "Mang A: ";
		for(int i=0; i<n; i++){
			cout << A[i] << " ";
		}

		cout << "\nDanh sach so nghich dao: " << endl;
		for(int i=0; i<n; i++){
			if(gcd(A[i],p)==1 and A[i]>0){
				cout <<A[i]<<"^-1 = " << phep_nghich_dao(A[i],p) << endl;
			}
		}
	return 0;
}