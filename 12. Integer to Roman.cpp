#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // Bảng ánh xạ giá trị của các ký tự Roman
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int total = 0; // Tổng kết quả
        int prevValue = 0; // Giá trị của ký tự trước đó

        // Duyệt qua từng ký tự trong chuỗi từ phải sang trái
        for (int i = s.size() - 1; i >= 0; i--) {
            int currentValue = romanValues[s[i]];

            // Nếu giá trị hiện tại nhỏ hơn giá trị trước đó, thực hiện phép trừ
            if (currentValue < prevValue) {
                total -= currentValue;
            } else {
                // Ngược lại, thực hiện phép cộng
                total += currentValue;
            }

            // Cập nhật giá trị trước đó
            prevValue = currentValue;
        }

        return total;
    }
};

int main() {
    // Tạo đối tượng Solution
    Solution solution;

    // Các ví dụ đầu vào
    string s1 = "III";
    string s2 = "LVIII";
    string s3 = "MCMXCIV";

    // Chuyển đổi và in kết quả
    cout << "Input: " << s1 << ", Output: " << solution.romanToInt(s1) << endl;
    cout << "Input: " << s2 << ", Output: " << solution.romanToInt(s2) << endl;
    cout << "Input: " << s3 << ", Output: " << solution.romanToInt(s3) << endl;

    return 0;
}
