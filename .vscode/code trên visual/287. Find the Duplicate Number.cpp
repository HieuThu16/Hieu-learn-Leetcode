#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]); // Lấy giá trị tuyệt đối
            if (index >= n) continue; // Kiểm tra tránh truy cập ngoài phạm vi
            if (nums[index] < 0) return index;
            nums[index] = -nums[index]; // Đánh dấu phần tử đã thấy
        }
        return -1;
    }
};

int main() {
    vector<int> nums = {3, 3, 3, 3, 3}; // Test case
    Solution solution;
    cout << "Duplicate number: " << solution.findDuplicate(nums) << endl;
    return 0;
}
