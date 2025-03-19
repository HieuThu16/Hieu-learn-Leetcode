#include <iostream>  
#include <string>  
#include <algorithm>  

using namespace std;  

bool areAnagramsSorting(string s, string t) {  
    if (s.length() != t.length()) return false; // Kiểm tra độ dài trước  

    sort(s.begin(), s.end()); // Sắp xếp chuỗi s  
    sort(t.begin(), t.end()); // Sắp xếp chuỗi t  

    return s == t; // So sánh hai chuỗi đã sắp xếp  
}  

int main() {  
    string s1 = "anagram";  
    string t1 = "nagaram";  
    cout << "Anagram (Sorting): " << areAnagramsSorting(s1, t1) << endl; // true  

    string s2 = "rat";  
    string t2 = "car";  
    cout << "Anagram (Sorting): " << areAnagramsSorting(s2, t2) << endl; // false  

    return 0;  
}  