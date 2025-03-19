#include <iostream>  
#include <string>  
#include <algorithm>  

using namespace std;  


// 2 con trỏ mà nên phải có left và right chứ đúng không 

bool isPalindrome(string s) {  
    int left = 0 ; int right = s.length() - 1 ;
    while(left < right ){
        while(left < right &&  !isalnum(s[left]))
            left++;
        while(left < right && !isalnum(s[right]))
            right--;
        if(tolower(s[left])!= tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true ; 
}  

int main() {  
    string s = "A man, a plan, a canal: Panama";  
    cout << "Chuỗi có phải là palindrome không: " << isPalindrome(s) << endl;  
    return 0;  
}  