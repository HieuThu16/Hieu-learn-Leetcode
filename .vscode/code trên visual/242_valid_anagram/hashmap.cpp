#include <iostream>  
#include <string>  
#include <unordered_map>  

using namespace std;  

bool areAnagramsHashMap(string s, string t) {  
    if (s.length() != t.length()) return false; // Kiểm tra độ dài trước  

    unordered_map<char, int> charCount; // Bảng băm để đếm ký tự  

    for (char c : s) {  
        charCount[c]++; // Tăng số lần xuất hiện của ký tự trong s  
    }  

    for (char c : t) {  
        charCount[c]--; // Giảm số lần xuất hiện của ký tự trong t  
        if (charCount[c] < 0) return false; // Nếu có ký tự nào trong t không đủ số lần trong s  
    }  

    return true;  
}  

int main() {  
    string s1 = "anagram";  
    string t1 = "nagaram";  
    cout << "Anagram (Hash Map): " << areAnagramsHashMap(s1, t1) << endl; // true  

    string s2 = "rat";  
    string t2 = "car";  
    cout << "Anagram (Hash Map): " << areAnagramsHashMap(s2, t2) << endl; // false  

    return 0;  
}  