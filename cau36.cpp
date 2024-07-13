#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> last_occurrence(const string& P){
	int m = P.length();
	vector<int> X;
	X.resize(256,-1);
    for(int i=0; i<m; i++){
    	X[static_cast<int>(P[i])] = i; // cập nhật vị trí cuối cùng trong mảng
	}
	
    return X;
}
 
int boyer_moore_search(const string& T, const string& P){
    int T_length = T.length(); // độ dài chuỗi cha
    int P_length = P.length(); // độ dài chuỗi con
 
 	if(P_length == 0 || T_length < P_length){
        return -1; // Không có kết quả nếu mẫu rỗng hoặc dài hơn văn bản
	}
    // Tạo bảng so khớp ký tự sai (bad character table)
    vector<int> X = last_occurrence(P);
 
    // Di chuyển chuỗi mẫu theo quy tắc lùi của bảng so khớp ký tự sai (bad character table)
    int i = P_length - 1; // bắt đầu từ vị trí cuối cùng
    while(i < T_length){
        int j = P_length - 1; // xuất phát từ vị trí cuối cùng
        while(T[i] == P[j]){
            if(j == 0){ //vị trí đầu mảng con
                return i;
            }
            //giảm vị trí 
            i--;
            j--;
        }
        if(T[i]!=P[i]){ // cập nhật lại bước nhảy i
        	i = i + P_length - min(j,1+X[static_cast<int>(T[i])]);
		}
    }
 
    return -1;
}
 
int main() {
    string T = "ABCABDABACDABABCABD";
    string P = "ABC";
    int result = boyer_moore_search(T,P);
    if(result!=-1){
        cout << "Vi tri dau tien cua chuoi mau la: " << result << endl;
	}else{
		cout << "Chuoi " << P << " khong co o trong " << T << endl;
	}
    return 0;
}