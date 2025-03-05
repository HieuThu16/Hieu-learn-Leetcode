#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một node trong BST
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm tìm node nhỏ nhất trong cây BST (dùng cho TH3)
TreeNode* findMin(TreeNode* node) {
    while (node->left) {
        node = node->left; // Tìm node nhỏ nhất (trái nhất)
    }
    return node;
}

// Hàm xóa một node trong BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;  // Nếu cây rỗng, trả về nullptr
    if(key < root->val){
        root->left = deleteNode(root->left , key );
    }
    else if(key > root->val){
        root->right = deleteNode(root->right , key);
    }
    else{
        if((!root->left)) return root->right ;
        if(!root->right) return root->left ;
        TreeNode* minNode = findMin(root->right);
        root->val = minNode ->val ;
        root->right = deleteNode(root->right , minNode->val);
    }

   return root ; 
}

// Hàm kiểm tra (main)
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int key = 3;
    root = deleteNode(root, key);

    cout << "Xoa node " << key << " thanh cong!\n";
    return 0;
}
