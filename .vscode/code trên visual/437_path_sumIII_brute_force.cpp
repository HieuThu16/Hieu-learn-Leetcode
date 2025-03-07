#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm đếm số đường đi bắt đầu từ một nút cụ thể
int countPathsFromNode(TreeNode* node, long long targetSum) {
   if(!node) return 0 ;
    int count = (node->val==targetSum) ? 1 : 0 ;
    count+= countPathsFromNode(node->left, targetSum - node->val);
    count+= countPathsFromNode(node->right, targetSum - node->val);

   return count ; 
}

// Hàm đếm tổng số đường đi trong cây
int pathSum(TreeNode* root, int targetSum) {
    if(!root) return 0 ;
    int count = countPathsFromNode(root, targetSum);
    // Đệ quy xét các nút con
    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);
    
    return count;
}

int main() {
    // Tạo cây nhị phân
    /*
            10
           /  \
          5   -3
         / \    \
        3   2   11
       / \   \
      3  -2   1
    */
    
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);
    
    int targetSum = 8;
    cout << "So duong di co tong bang " << targetSum << " la: " << pathSum(root, targetSum) << endl;

    return 0;
}