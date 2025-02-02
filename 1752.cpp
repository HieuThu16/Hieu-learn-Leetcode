#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int>& nums, int start, int end) {
    for (int i = start; i < end; i++) {
        if (nums[i] > nums[i + 1]) return false;
    }
    return true;
}

bool check(vector<int>& nums) {
    int n = nums.size();
    int pivot = -1;

    // Tìm vị trí pivot
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            pivot = i;
            break;
        }
    }

    // Nếu không có pivot, mảng đã sorted
    if (pivot == -1) return true;

    // Kiểm tra phần còn lại sau pivot
    return isSorted(nums, pivot + 1, n - 1) && nums[n - 1] <= nums[0];
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};
    vector<int> nums3 = {1, 2, 3, 4, 5};
    
    cout << check(nums1) << endl; // Output: true
    cout << check(nums2) << endl; // Output: false
    cout << check(nums3) << endl; // Output: true

    return 0;
}
