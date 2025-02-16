// Phân tích đề
// Cho một chuỗi s gồm chữ cái viết hoa và viết thường. Ta cần tìm độ dài của palindrome dài nhất có thể được tạo ra từ các chữ cái trong s.

// Palindrome là gì?
// Một chuỗi là palindrome nếu nó đọc xuôi hay ngược đều giống nhau. Ví dụ:

// ✅ racecar, abba, aabaa là palindrome.
// ❌ abc, aabbcc không phải palindrome.

// Quan sát quan trọng
// Mỗi ký tự trong palindrome phải xuất hiện một số lần chẵn, ngoại trừ tối đa một ký tự có thể xuất hiện lẻ (vì nó có thể nằm giữa).
// Ví dụ:
// "aabb" → Có thể tạo "abba" (palindrome).
// "aaabb" → Có thể tạo "ababa" (palindrome).
// "abc" → Không thể tạo palindrome dài hơn 1 vì tất cả ký tự có số lần xuất hiện lẻ.

// Chỉ cần đếm số phần tử có số lần lặp chẵn và +1 ( là phần tử lẻ ở chính giữa là được )
// Vì đề chỉ cần output là độ dài 
#include <iostream>
#include <unordered_map>
using namespace std;

int longestPalindrome(string s) {
    unordered_map<char, int> freq;
    for(char c : s )
        freq[c]++;

    int length = 0 ;
    bool hasOdd = false ; // xem có phần tử lẻ nào không 

    for(auto it: freq){
        if(it.second %2 == 0 ){
            length += it.second ; 
                
        }
        else { // Nếu tần suất lẻ, lấy số chẵn gần nhất + 1 ký tự lẻ duy nhất
            length += it.second - 1;
            hasOdd = true;
        }
    }
      if (hasOdd) length++;

    return length;

        
}

int main() {
    string s = "abccccdd";
    cout << "Độ dài palindrome dài nhất: " << longestPalindrome(s) << endl;
    return 0;
}


