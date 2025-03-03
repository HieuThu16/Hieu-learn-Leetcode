#include <iostream>
using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm tính độ sâu tối đa của cây nhị phân
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    // Tạo cây ví dụ
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Độ sâu tối đa của cây: " << maxDepth(root) << endl;
    
    return 0;
}
