#include <iostream>
#include <string>
using namespace std;

// Hàm đệ quy đảo ngược chuỗi
void reverseStringRecursive(string &str, int l, int r) {
    if (l >= r) {
        return; // Điều kiện dừng: khi con trỏ trái >= con trỏ phải
    }
    // Hoán đổi ký tự tại vị trí l và r
    swap(str[l], str[r]);

    // Gọi đệ quy với các con trỏ tiến về phía giữa
    reverseStringRecursive(str, l + 1, r - 1);
}

int main() {
    string input;
    cout << "Nhap chuoi can dao nguoc: ";
    getline(cin, input);

    reverseStringRecursive(input, 0, input.length() - 1);

    cout << "Chuoi sau khi dao nguoc: " << input << endl;
    return 0;
}
