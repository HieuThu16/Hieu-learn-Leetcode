#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) { // Cách 1 
    stringstream ss(s);
    string word;
    vector<string> words;

    // Tách từ và lưu vào vector
    while (ss >> word) {
        words.push_back(word);
    }

    // Tạo kết quả bằng cách nối từ cuối về đầu
    stringstream result;
    for (int i = words.size() - 1; i >= 0; i--) {
        result << words[i];
        if (i > 0) {
            result << " ";
        }
    }

    return result.str();
}
string reserseWords2(string s){ // Cách 2
   string result;
   int i = s.length() - 1;
   while (i >= 0) {
         while(i>=0 && s[i] == ' ') i--;
         if(i<0) break;
         int j = i;
         while(i>=0 && s[i] != ' ') i--;
         if(result.empty()){
              result = s.substr(i+1, j-i);
         }else{
              result = result + ' ' + s.substr(i+1, j-i);
         }
   }
   return result;
}     

int main() {
    string s = "  Hello   world! nef  ";
    cout << '"' << reserseWords2(s) << '"' << endl; // Output: "world! Hello"
    return 0;
}

