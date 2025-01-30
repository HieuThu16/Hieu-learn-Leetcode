#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // Xử lý trường hợp cơ bản
        if (n == 0) return 1; // x^0 = 1
        if (x == 0) return 0; // 0^n = 0, nếu n > 0

        // Nếu n âm, chuyển thành 1/(x^|n|)
        long long exp = n; // Dùng long long để tránh tràn số
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        // Sử dụng phương pháp Exponentiation by Squaring
        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) { // Nếu lũy thừa lẻ
                result *= x;
            }
            x *= x; // Bình phương cơ số
            exp /= 2; // Giảm lũy thừa
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    double x1 = 2.00000;
    int n1 = 10;
    cout << "pow(" << x1 << ", " << n1 << ") = " << solution.myPow(x1, n1) << endl;

    // Test case 2
    double x2 = 2.10000;
    int n2 = 3;
    cout << "pow(" << x2 << ", " << n2 << ") = " << solution.myPow(x2, n2) << endl;

    // Test case 3
    double x3 = 2.00000;
    int n3 = -2;
    cout << "pow(" << x3 << ", " << n3 << ") = " << solution.myPow(x3, n3) << endl;

    return 0;
}
