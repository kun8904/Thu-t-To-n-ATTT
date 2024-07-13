#include <iostream>
#include <vector>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool check_snt(int n){
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i<=n; i += 6){
        if (n%i == 0 || n%(i + 2) == 0) return false;
    }
    return true;
}

int main(){
    int a, b;
    cout << "Nhap khoang a, b: ";
    cin >> a >> b;

    // Tạo các mảng S1 và S2 chứa các giá trị bình phương của các số nguyên
    vector<int> S1, S2;
    for(int i=0; i*i<= b; i++){
        S1.push_back(i*i);
        S2.push_back(i*i);
    }

    // Tìm các số nguyên tố trong khoảng [a, b] thỏa mãn điều kiện
    int count = 0;
    for(int i=a; i<=b; i++){
        if(check_snt(i)){
			for(int j=0; j<S1.size(); j++){
				for(int t=j; t<S2.size(); t++){
					if(i == S1[j]+S2[t]){
						count++;
					}
				}
			}
        }
    }

    cout << "So luong cac so nguyen to thoa man dieu kien: " << count << endl;

    return 0;
}
