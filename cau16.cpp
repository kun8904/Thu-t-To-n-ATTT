#include <iostream>
#include <vector>
#include <cstdlib> // Thư viện cho rand() và srand()
#include <ctime>   // Thư viện cho time()
using namespace std;

bool check_snt(int n){
	if(n<=1) return false;
	if(n<=3) return true;
	if(n%2 == 0 || n%3 == 0) return false;
	for(int i=5; i*i<=n; i++){
		if(n%i==0) return false;
	} 
	return true;
}

int main(){
	vector<int> X(0);
	int n;
	int check=0;
	
	//khởi tạo bộ sinh số ngẫu nhiên
	srand(time(0));
	
	cout << "Nhap n: "; cin >> n; 
	cout << "Mang sinh ngau nhien: ";
	for(int i=0; i<n; i++){
		int tmp = rand() % 100 + 1;
		X.push_back(tmp);
		cout << X[i] << " ";
	}
	
    cout << endl << "Cac so nguyen to trong mang: ";
    for(int i=0; i<n; i++){
        if(check_snt(X[i])){
            cout << X[i] << " ";
            check++;
        }
    }
    
	if(check==0){
		cout << "\nKhong co so ngto nao trong mang sinh!!"<< endl;
	}
}
