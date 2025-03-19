#include <iostream>  
#include <string>  
#include <array>  

using namespace std;  

bool areAnagramsArray(string s, string t) {  
    if (s.length() != t.length()) return false; // Kiểm tra độ dài trước  

    array<int, 26> charCount = {0}; // Mảng để đếm ký tự (cho 26 ký tự chữ cái)  

    for (char c : s) {  
        charCount[c - 'a']++; // Tăng số lần xuất hiện của ký tự trong s  
    }  

    for (char c : t) {  
        charCount[c - 'a']--; // Giảm số lần xuất hiện của ký tự trong t  
        if (charCount[c - 'a'] < 0) return false; // Nếu có ký tự nào trong t không đủ số lần trong s  
    }  

    return true;  
}  

int main() {  
    string s1 = "anagram";  
    string t1 = "nagaram";  
    cout << "Anagram (Array Count): " << areAnagramsArray(s1, t1) << endl; // true  

    string s2 = "rat";  
    string t2 = "car";  
    cout << "Anagram (Array Count): " << areAnagramsArray(s2, t2) << endl; // false  

    return 0;  
}  