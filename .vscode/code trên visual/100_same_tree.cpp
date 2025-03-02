#include <iostream>

using namespace std;

// Định nghĩa cấu trúc của một node trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm kiểm tra hai cây có giống nhau không
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true; // Cả hai cây đều rỗng
    if (!p || !q) return false; // Một trong hai cây rỗng
    if (p->val != q->val) return false; // Giá trị của node không giống nhau
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    
    if (isSameTree(p, q)) {
        cout << "Two trees are the same." << endl;
    } else {
        cout << "Two trees are different." << endl;
    }
    
    return 0;
}
