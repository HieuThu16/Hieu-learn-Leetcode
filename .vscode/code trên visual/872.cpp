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

// Hàm duyệt cây để lấy danh sách giá trị lá
void getLeafValues(TreeNode* root , vector<int>& leaves){
    if(root == NULL ) return ;
    if(!root->left && !root->right)
        leaves.push_back(root->val);
    getLeafValues(root->left, leaves);
    getLeafValues(root->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaves1, leaves2;
    getLeafValues(root1, leaves1);
    getLeafValues(root2, leaves2);
    return leaves1 == leaves2;
}


int main() {
    // Tạo cây ví dụ
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(7);
    root1->right->right = new TreeNode(4);

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(9);
    root2->right = new TreeNode(8);
    root2->left->left = new TreeNode(6);
    root2->right->left = new TreeNode(7);
    root2->right->right = new TreeNode(4);

    cout << (leafSimilar(root1, root2) ? "True" : "False") << endl;
    
    return 0;
}
