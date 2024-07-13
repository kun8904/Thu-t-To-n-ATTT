#include <iostream>
#include <vector>
using namespace std;

// kiểm tra số nguyên tố
bool check_snt(int a){ 
	if(a<=1) return false;
	if(a<=3) return true;
	if(a%2==0 or a%3==0) return false;
	for(int i=5; i*i<=a; i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

// kiểm tra UCLN là snt
bool gcd_snt(int a, int b){
	if(a<=0 or b<=0){
		return false;
	}
	
	// đảo vị trí
    int tmp,check;
	if(a>=b){
		tmp = b;
	}else{
		tmp = a;
	}
	
	// hàm tìm UCLN
	for(int i=1; i<=tmp; i++){
		if(a%i==0 and b%i==0){
			check = i;
		}
	}
	if(check_snt(check)){
		return true;
	}
	return false;
}

// kiểm tra cặp số đã tồn tại trong vector chưa
bool check_trunglap(vector<pair<int, int>>& X, int a, int b){ // hàm này nếu đúng thì bỏ qua ở hàm main còn sai thì add vào vector ở hàm main
    for(auto p : X){
        if((p.first == a && p.second == b) || (p.first == b && p.second == a)){
            return true;
        }
    }
    return false;
}

int main(){
	vector<int> A;
	int dem=0;
	int n; // n là độ dài của mảng
	do{
		cout << "Nhap do dai cua mang n = " ; cin >> n; 
	}while(n<=0);
	A.resize(n);
	for(int i=0; i<n; i++){
	 	cout << "A["<<i+1<<"] = "; cin >> A[i];
	}
	
	vector<pair<int, int>> X; // pair cho phép lưu 1 cặp số

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(gcd_snt(A[i],A[j])){
				if (!check_trunglap(X, A[i], A[j])){ // kiểm tra sự trùng lặp các cặp số
                    dem++;
                    X.push_back(make_pair(A[i], A[j])); // push 1 cặp số vào vector
                }
			}
		}
	}
	cout << "So cap thoa man dieu kien la: " << dem << endl;
}