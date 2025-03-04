#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // XOR tất cả các phần tử trong mảng
    }
    return result;
}

// Hàm kiểm tra
int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Phan tu xuat hien duy nhat: " << singleNumber(nums) << endl;
    return 0;
}
