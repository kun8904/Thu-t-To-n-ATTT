#include <iostream>
#include <math.h>
#include <vector>
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
	vector<int> X(0);
	int nguoc,b;
	for(int i=pow(10,2); i<pow(10,3);i++){
		b=i;
		nguoc=0;
		if(check_snt(i)){
			for(int j=1; j<=3; j++){
				nguoc = nguoc*10 + b%10;
				b = b/10;
			}
			for(int t =1; t<=nguoc; t++){
				if(nguoc == t*t){
					cout << i << endl;
				}
			}
		}
	}
	
}