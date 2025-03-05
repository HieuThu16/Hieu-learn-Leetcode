#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;  // Trường hợp cây rỗng
        
        // Nếu là nút lá, kiểm tra xem tổng còn lại có bằng 0 không
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Kiểm tra đệ quy trên nhánh trái và nhánh phải
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

// Hàm kiểm tra
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;
    std::cout << (sol.hasPathSum(root, targetSum) ? "True" : "False") << std::endl; // Output: True

    return 0;
}
