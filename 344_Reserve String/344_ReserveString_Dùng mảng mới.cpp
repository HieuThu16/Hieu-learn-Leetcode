#include <iostream>
#include <string>
using namespace std;

string reverseStringUsingNewString(const string &str) {
    string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

int main() {
    string input;
    cout << "Nhap chuoi can dao nguoc: ";
    getline(cin, input);

    string reversed = reverseStringUsingNewString(input);

    cout << "Chuoi sau khi dao nguoc: " << reversed << endl;
    return 0;
}
