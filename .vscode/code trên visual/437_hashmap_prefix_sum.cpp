#include <iostream>
#include <unordered_map>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm đếm số đường đi bằng kỹ thuật prefix sum
int countPaths(TreeNode* node, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSumMap) {
    if (!node) return 0;
    
    // Cập nhật tổng hiện tại
    currentSum += node->val;
    
    // Đếm số đường đi có tổng bằng targetSum
    int count = 0;
    if (prefixSumMap.find(currentSum - targetSum) != prefixSumMap.end()) {
        count += prefixSumMap[currentSum - targetSum];
    }
    
    // Cập nhật prefixSumMap
    prefixSumMap[currentSum]++;
    
    // Đệ quy duyệt cây con
    count += countPaths(node->left, currentSum, targetSum, prefixSumMap);
    count += countPaths(node->right, currentSum, targetSum, prefixSumMap);
    
    // Backtrack: Loại bỏ tổng hiện tại khi quay lui
    prefixSumMap[currentSum]--;
    
    return count;
}

// Hàm chính
int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long long, int> prefixSumMap;
    prefixSumMap[0] = 1;  // Cần thiết để xử lý trường hợp có tổng bằng targetSum ngay từ đầu
    
    return countPaths(root, 0, targetSum, prefixSumMap);
}
