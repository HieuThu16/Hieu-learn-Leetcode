#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
   int total =0 ;
   for(int num : nums)
         total += num ;
    int sum = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        if(sum == total - sum - nums[i])
            return i ;
        sum +=nums[i];
    }
    return -1 ; 

}

int main() {
    // Ví dụ sử dụng
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int pivot = pivotIndex(nums);
    
    if (pivot != -1) {
        cout << "Pivot index: " << pivot << endl;
    } else {
        cout << "Không tồn tại pivot index." << endl;
    }
    
    return 0;
}
