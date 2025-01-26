#include <iostream>
#include <string>
using namespace std; 
class Solution {
    public : 
        int lengthOfLastWord(string s ){
            int length = 0 ;
            int i = s.size()- 1 ;
            // Bước 1 : Bỏ qua các khoảng trắng 
            while(i>= 0 && s[i]==' '){
                i--; 
            }
            // Bước 2 đếm độ dài từ cuối cùng 
            while(i >= 0 && s[i]!= ' '){
                length++ ;
                i-- ; 
            }
            return length ; 
        }
};
int main(){
        Solution solution;
    string s1 = "Hello world";
    cout << solution.lengthOfLastWord(s1) ; 
}