#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isSpecialArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            // Kiểm tra nếu hai số liên tiếp có cùng tính chẵn/lẻ
            if ((nums[i] % 2) == (nums[i + 1] % 2)) {
                return false; // Không phải special array
            }
        }
        return true; // Là special array
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test 1: " << (solution.isSpecialArray(nums1) ? "true" : "false") << endl;

    // Test case 2
    vector<int> nums2 = {2, 4, 6, 8};
    cout << "Test 2: " << (solution.isSpecialArray(nums2) ? "true" : "false") << endl;

    // Test case 3
    vector<int> nums3 = {5, 10, 15, 20, 25};
    cout << "Test 3: " << (solution.isSpecialArray(nums3) ? "true" : "false") << endl;

    // Test case 4
    vector<int> nums4 = {2, 1, 4, 3, 6, 5};
    cout << "Test 4: " << (solution.isSpecialArray(nums4) ? "true" : "false") << endl;

    return 0;
}
