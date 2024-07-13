#include <iostream>
#include <math.h>
using namespace std;


int main(){
	int n;
	int x=0;
	cout << "Nhap n: ";
	cin >> n;
	for(int q=1; q<=n; q++){
		for(int i=1; i<=q; i++){
			if(q%i==0){
				x++;
			}
		}
		if(x==4){
			cout << q << endl;
		}
		x=0;
	}
	return 0;
}