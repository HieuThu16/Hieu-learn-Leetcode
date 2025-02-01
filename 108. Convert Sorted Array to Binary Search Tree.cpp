#include <iostream>
#include <vector>

using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Điều kiện dừng đệ quy
        if (left > right) return NULL;

        // Chọn phần tử ở giữa làm root
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        // Đệ quy tạo cây con bên trái
        root->left = buildBST(nums, left, mid - 1);

        // Đệ quy tạo cây con bên phải
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};

// Hàm in cây theo thứ tự inorder (Duyệt trung thứ tự - Left, Root, Right)
void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution solution;
    
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* root = solution.sortedArrayToBST(nums);

    cout << "Inorder traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
