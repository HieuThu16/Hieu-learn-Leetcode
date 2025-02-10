#include <iostream>

bool isPerfectSquare(int num) {
    if (num < 1) return false;
    
    long long left = 1, right = num;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == num) {
            return true;
        } else if (square < num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return false;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (isPerfectSquare(num)) {
        std::cout << num << " is a perfect square.\n";
    } else {
        std::cout << num << " is not a perfect square.\n";
    }

    return 0;
}
