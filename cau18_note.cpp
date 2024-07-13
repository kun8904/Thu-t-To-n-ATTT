#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// Hàm để tính tổng của hai số nguyên lớn dưới dạng chuỗi
string addLargeNumbers(const string &num1, const string &num2){
    int len1 = num1.size();
    int len2 = num2.size();
    int maxLen = max(len1, len2);

    string result = "";
    int carry = 0;
    
    // Duyệt từng chữ số từ phải sang trái
    for(int i = 0; i < maxLen; ++i){
        int digit1 = (i < len1) ? num1[len1 - 1 - i] - '0' : 0;
        int digit2 = (i < len2) ? num2[len2 - 1 - i] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    
    // Nếu còn dư carry, thêm vào kết quả
    if (carry) {
        result += carry + '0';
    }
    
    // Đảo ngược chuỗi kết quả vì chúng ta đã thêm các chữ số từ phải sang trái
    reverse(result.begin(), result.end());
    
    return result;
}

// Hàm chuyển chuỗi kết quả thành mảng các chữ số
vector<int> convertToArray(const string &num){
    vector<int> result;
    for(char digit : num){
        result.push_back(digit - '0');
    }
    return result;
}

int main(){
   	string num1, num2;
    
    cout << "Nhap so nguyen lon nhat: ";
    cin >> num1;
    cout << "Nhap so nguyen lon thu 2: ";
    cin >> num2;
    
    // Tính tổng hai số
    string sum = addLargeNumbers(num1, num2);
    
    // Chuyển kết quả thành mảng các chữ số
    vector<int> sumArray = convertToArray(sum);
    
    // Hiển thị kết quả dưới dạng mảng
    cout << "Tong duoi dang mang: [ ";
    for (int digit : sumArray) {
        cout << digit << " ";
    }
    cout << "]\n";
    
    // Hiển thị kết quả dưới dạng số nguyên
    cout << "Tong duoi dang so nguyen: " << sum << "\n";
    
    return 0;
}
