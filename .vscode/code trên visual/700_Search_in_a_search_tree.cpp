#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một node trong cây BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm tìm kiếm node trong BST (đệ quy)
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) 
        return root;  // Trả về node tìm thấy hoặc nullptr nếu không tìm thấy

    if (val < root->val) 
        return searchBST(root->left, val);  // Tìm ở nhánh trái

    return searchBST(root->right, val);  // Tìm ở nhánh phải
}

// Hàm kiểm tra
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;
    TreeNode* result = searchBST(root, val);

    if (result) {
        cout << "Tim thay node co gia tri " << val << endl;
    } else {
        cout << "Khong tim thay node" << endl;
    }

    return 0;
}
