#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cout << "Nhap so n: " ; cin >> n;
	vector<int> X(n+1);
	vector<int> T(n+1);
	for(int i=1;i<=n; i++){
		X[i] = i;
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<X[i]; j++){
			if(X[i]%j==0){
				T[i] += j;
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(X[i]==T[j] and X[j]==T[i]){
				cout << X[i] << " " << X[j] << endl;
			}
		}
	}
	return 0;
}