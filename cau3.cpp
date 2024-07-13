#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int N,a=0;
	cout << "Nhap N= ";
	cin >> N;
	int k,q,p,s;
	if(N>2){
		k=1;
		q=2;
		p=3;
		s=2;
		for(int i=3; i<=N; i++){
			if(N%i==0){
				s++;
				p +=i;
				for(int j=2; j<= sqrt(i); j++){
					if(i%j==0){
						a++;
					}
				}
				if(a==0){
					q += i;
					k++;
				}
				a=0;
			}
		}
		cout << N+p+s-q-k << endl;
	}else{
		if(N=1){
			k=0;
			q=0;
			p=1;
			s=1;
			cout << N+p+s-q-k << endl;
		}
		if(N=2){
			k=1;
			q=2;
			p=3;
			s=2;
			cout << N+p+s-q-k << endl;
		}
	}
	
	return 0;	
}