#include <iostream>
using namespace std;


// Có chuỗi t , nếu xóa đi kí tự của chuỗi t , thì có ra chuỗi s hay không  

// Chạy trên từng chuỗi 


// Nếu s khớp với t thì tăng s lên để kiểm tra kí tự tiếp theo 
// Nếu không khớp thì cứ tăng t lên để xem có khớp không 
// Nếu cuối cùng , tăng đến khi nào i == số lượng phần tử của s , thì coi như là duyệt hết 
// chuỗi s rồi đó , nên là true 


bool isSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    int i = 0, j = 0;
    
    while (i < m && j < n) {
        if (s[i] == t[j]) {
            i++; // Nếu ký tự khớp, di chuyển con trỏ của s
        }
        j++; // Luôn di chuyển con trỏ của t
    }
    
    return i == m; // Nếu duyệt hết s, nghĩa là s là subsequence của t
}

int main() {
    string s = "ace";
    string t = "abcde";
    
    if (isSubsequence(s, t)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
