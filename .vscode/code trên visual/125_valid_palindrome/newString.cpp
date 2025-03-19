#include <iostream>  
#include <string>  
#include <algorithm>  

using namespace std;  

bool isPalindromeNewString(string s) {  
    string newString = "";
    for(char c: s )
        if(isalnum(c))
            newString += tolower(c);
    string reversed = newString;
    reverse(reversed.begin(), reversed.end());
    return newString == reversed;
}  

int main() {  
    string s = "A man, a plan, a canal: Panama";  
    cout << "Chuỗi có phải là palindrome không (Tạo chuỗi mới): " << isPalindromeNewString(s) << endl;  
    return 0;  
}  