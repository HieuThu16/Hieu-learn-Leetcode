#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4};

    // Create an instance of the Solution class
    Solution solution;

    // Call the runningSum method
    vector<int> result = solution.runningSum(nums);

    // Print the result
    cout << "Running Sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
