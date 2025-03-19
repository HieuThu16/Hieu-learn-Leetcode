#include <iostream>
#include <vector>
#include <climits>

using namespace std;


// Duyệt mảng đến khi nào tổng lớn hơn target thì bắt đầu xử lý 
// Nếu tổng lớn hơn target thì cập nhật độ dài nhỏ nhất
// Sau đó , giảm tổng đi cho đến khi nào tổng nhỏ hơn target thì tiếp tục duyệt ( tăng left lên 1 -> Để trượt )
// Nếu cuối cùng không tìm được thì trả về 0 , nếu tìm được thì trả về độ dài nhỏ nhất

class Solution{
    public:
        int minSubArrayLen(int target , vector<int>& nums){
            int n = nums.size();
            int left = 0 , sum = 0 ;
            int minLength = INT_MAX; 
            for (int i = 0 ; i < n ; i++ ){
                sum+=nums[i];
                while(sum>target){
                    minLength = min(minLength , i - left + 1);
                    sum-=nums[left++];
                }
            }
        return minLength == INT_MAX ? 0 : minLength; // Tr
        }
};
int main() {  
    Solution sol;  
    vector<int> nums = {2, 3, 1, 2, 4, 3};  
    int target = 7;  
    
    int result = sol.minSubArrayLen(target, nums);  
    cout << "Minimum Size Subarray Sum: " << result << endl; // Output: 2  
    
    return 0;  
}  
