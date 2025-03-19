#include <iostream>  
#include <string>  
#include <algorithm>  

using namespace std;  

// Hàm kiểm tra kí tự là số nguyên âm
bool isVowel(char c ){ // truyền vào 1 kí tự 
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'); // nếu kí tự là nguyên âm thì trả về true
}



// Phương pháp kiểu như cho k số đầu , k số đó là thõa mãn 
// Sau đó , duyệt từ k đến hết chuỗi , nếu kí tự đó là nguyên âm thì tăng biến đếm lên
// Nếu kí tự đầu tiên là nguyên âm thì giảm biến đếm đi

int maxVowelsSlidingWindow(string s, int k) { // s là chuỗi , k là độ dài chuỗi concon
    int max = 0 ; // Đầu tiên muốn tìm max thì khởi tạo biến để lưu max 
    int currentVowels = 0 ; 
    int n = s.length(); // Đương nhiên là phải có độ dài chuỗi s rồi
    for(int i = 0 ; i < k ; i++){
        if (isVowel(s[i]))
            currentVowels++; // Nếu kí tự đó là nguyên âm thì tăng biến đếm lên
    }
    max = currentVowels; // Gán maxVowels = currentVowels 


    for(int i = k ; i < n ; i++){
        if(isVowel(s[i-k]))
            currentVowels--; // Nếu kí tự đầu tiên là nguyên âm thì giảm biến đếm đi
        if(isVowel(s[i]))
            currentVowels++; // 
        max = max > currentVowels ? max : currentVowels; // Nếu kí tự đó là nguyên âm thì tăng biến đếm lên
    }
    return max ; 
}

int main() {  
    string s = "abciiidef";  
    int k = 3;  
    cout << "Số lượng nguyên âm lớn nhất (Sliding Window): " << maxVowelsSlidingWindow(s, k) << endl;  
    return 0;  
}  