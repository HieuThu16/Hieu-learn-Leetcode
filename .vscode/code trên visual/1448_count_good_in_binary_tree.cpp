#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một node trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm đệ quy để đếm số lượng good nodes
int countGoodNodes(TreeNode* node, int max_value) {
   if(!node) return 0 ;
   int count = node->val >= max_value ? 1 : 0 ;
    max_value = max(max_value, node->val);
    return count + countGoodNodes(node->left, max_value) + countGoodNodes(node->right, max_value);
}

// Hàm chính để gọi đệ quy
int goodNodes(TreeNode* root) {
    return countGoodNodes(root, root->val);
}

// Hàm kiểm tra
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(5);

    cout << "So luong good nodes: " << goodNodes(root) << endl;
    return 0;
}
