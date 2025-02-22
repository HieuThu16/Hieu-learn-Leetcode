#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseStringUsingStack(string &str) {
    stack<char> s;

    // Đẩy từng ký tự của chuỗi vào stack
    for (char c : str) {
        s.push(c);
    }

    // Lấy ký tự từ stack để đảo ngược chuỗi
    for (int i = 0; i < str.length(); i++) {
        str[i] = s.top(); // Lấy phần tử trên cùng của stack
        s.pop();          // Xóa phần tử đó khỏi stack
    }
}

int main() {
    string input;
    cout << "Nhap chuoi can dao nguoc: ";
    getline(cin, input);

    reverseStringUsingStack(input);

    cout << "Chuoi sau khi dao nguoc: " << input << endl;
    return 0;
}
