#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string reverseVowels(string s ){
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    int left = 0 , right = s.length()- 1 ;
    while(left < right ){
        while(left< right && vowels.find(s[left])==vowels.end()){
            left++;
        }
        while(left< right && vowels.find(s[right])==vowels.end()){
            right--;
        }
        if(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    return s ; 
}
int main() {
    string s;
    cout << "Nhập chuỗi: ";
    getline(cin, s);
    cout << "Chuỗi sau khi đảo nguyên âm: " << reverseVowels(s) << endl;
    return 0;
}
