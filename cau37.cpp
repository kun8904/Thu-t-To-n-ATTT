#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Hàm tiền xử lý mẫu để tạo bảng tiền tố
vector<int> failure_function(const string& pattern){
    int m = pattern.length();
    vector<int> X(m);

	for(int i=0; i<m; i++){
		int check=0;
		if(i==0){
			X[i] = -1;
		}else if(i==1){
			X[i] = 0;
		}else{
			// i=1 -> i=5
			vector<string> A;
			vector<string> B;
			
			// tiền tố
			for(int j=0; j<=i-1; j++){
				A.push_back(pattern.substr(0,j+1));
			}
			
			// hậu tố
			int x=0;
			for(int j=i-1; j>=1; j--){
				x++;
				B.push_back(pattern.substr(j,x));
			}
			
			// so sánh
			for(int j=0; j<B.size(); j++){
				for(int k=0; k<A.size(); k++){
					if(B[j]==A[k]){
						check++;
					}
				}
			}
			X[i] = check;
		}
	}
    return X;
} 

// Hàm thực hiện tìm kiếm KMP
vector<int> KMPsearch(const string& T, const string& P){
    vector<int> result;
    int n = T.length();
    int m = P.length();

    if(m == 0 || n < m){
        return result; // Không có kết quả nếu mẫu rỗng hoặc dài hơn văn bản
	}
    vector<int> X = failure_function(P);
    
    int j = 0;
    for(int i = 0; i < n; ++i){
        while(j > 0 && T[i]!=P[j]){
            j = X[j - 1];  
        }
        
        if(T[i] == P[j]){
            ++j;
        }
        
        if(j == m){
            result.push_back(i - m + 1); // Tìm thấy mẫu tại vị trí (i - m + 1)
            j = X[j - 1]; // trả về giá trị của j-1 để tiếp tục tìm kiếm (vẫn i++ nhưng nếu k tm thì đệ quy j về j-1
        }
    }

    return result;
}

int main() {
    string S1 = "cab"; // Mẫu cần tìm
    string S2 = "ababcabcabababd"; // Văn bản chứa mẫu

    vector<int> matches = KMPsearch(S2, S1);

    cout << "Mau xuat hien tai cac chi so: ";
    for(int index : matches){
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
