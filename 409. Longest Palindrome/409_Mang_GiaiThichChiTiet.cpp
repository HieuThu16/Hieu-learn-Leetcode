#include <iostream>
#include <vector>
using namespace std;

//✅ Mục tiêu: Chúng ta muốn xây dựng một palindrome dài nhất có thể từ các ký tự của chuỗi.

// Mỗi ký tự có số lần xuất hiện chẵn có thể được sử dụng toàn bộ.
// Mỗi ký tự có số lần xuất hiện lẻ: ta chỉ lấy phần chẵn của nó (bỏ đi 1 ký tự) để đảm bảo có thể sắp xếp đối xứng.
// Nếu có ít nhất một ký tự lẻ, ta có thể đặt 1 ký tự lẻ vào giữa của palindrome.



// Ký tự	Số lần xuất hiện	Xử lý	Được thêm vào palindrome
// a	1 (lẻ)	Lấy 1 - 1 = 0, đánh dấu hasOdd = true	0
// b	1 (lẻ)	Lấy 1 - 1 = 0, đánh dấu hasOdd = true	0
// c	4 (chẵn)	Lấy toàn bộ 4	4
// d	2 (chẵn)	Lấy toàn bộ 2	2
// 📌 Tổng cộng: 4 + 2 + 0 + 0 = 6, nhưng do hasOdd = true, ta có thể thêm 1 ký tự lẻ vào giữa.
// 💡 Kết quả cuối cùng: 6 + 1 = 7


int longestPalindrome(string s) {
    vector<int> freq(128, 0); // ASCII có 128 ký tự

    // Đếm tần suất xuất hiện của từng ký tự
    for (char c : s) {
        freq[c]++;
    }

    int length = 0;
    bool hasOdd = false;

    // Duyệt mảng tần suất
  for (int count : freq) {
    if (count % 2 == 0) {  // Nếu số lần xuất hiện của ký tự là số chẵn
        length += count;
    } else {  // Nếu số lần xuất hiện của ký tự là số lẻ
        length += count - 1;  // Lấy phần chẵn của nó
        hasOdd = true;  // Đánh dấu rằng có ít nhất một ký tự lẻ
    }
}


    // Nếu có ít nhất một ký tự lẻ, thêm 1 vào giữa
    if (hasOdd) length++;

    return length;
}

int main() {
    string s = "abccccdd";
    cout << "Độ dài palindrome dài nhất: " << longestPalindrome(s) << endl;
    return 0;
}

// ### **Tóm lại**
// - Nếu **số lần xuất hiện là chẵn**, lấy toàn bộ.  
// - Nếu **số lần xuất hiện là lẻ**, lấy số chẵn gần nhất (`count - 1`) và đánh dấu rằng có ít nhất một ký tự lẻ (`hasOdd = true`).  
// - Nếu có **ít nhất một ký tự lẻ**, ta có thể thêm **1 ký tự lẻ vào giữa** palindrome.
