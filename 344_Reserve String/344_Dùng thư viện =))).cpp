#include <iostream>
#include <string>
#include <algorithm> // Thư viện chứa hàm reverse
using namespace std;

int main() {
    string input;
    cout << "Nhap chuoi can dao nguoc: ";
    getline(cin, input);

    // Sử dụng hàm reverse của STL
    reverse(input.begin(), input.end());

    cout << "Chuoi sau khi dao nguoc: " << input << endl;
    return 0;
}
