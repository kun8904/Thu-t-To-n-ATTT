#include <iostream>
#include <vector>
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
	vector<int> T; //vector số nguyên tố
	int n,tong;
	cout <<"Nhap n: " ; cin >> n;
	for(int i=1; i<=n; i++){
		if(check_snt(i)){
			T.push_back(i);
		}
	}
	for(int i=0; i<T.size(); i++){
		tong=0;
		
		if(i+4<=T.size()){
			for(int j=i; j<i+5; j++){
				tong += T[j];
			}

			if(check_snt(tong)){
				for(int j=i; j<i+5;j++){
					cout << T[j] <<" ";
				}
			}
		}
		cout << endl;
	}
}