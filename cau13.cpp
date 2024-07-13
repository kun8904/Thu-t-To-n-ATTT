#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool check_snt(int a){
    if(a<=1) return false;
    if(a<=3) return true;
    if(a%2 == 0 || a%3 == 0) return false;
    for(int i = 5; i*i<= a; i+=6){
        if (a % i == 0 ) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    vector<int> X;
    for(int i=2; i <= n; i++){
        if(check_snt(i)){
            X.push_back(i); // chứa các số nguyên tố 
        }
    }
    for(int i =0; i<X.size(); i++){
    	int tong =0, hieu =0;
        for(int j = i+1; j<X.size(); j++){
            tong = X[i] + X[j];
            hieu = abs(X[i] - X[j]);
            if(check_snt(tong) && check_snt(hieu)){
                cout << X[i] << " " << X[j] << endl;
            }
        }
    }

    return 0;
}