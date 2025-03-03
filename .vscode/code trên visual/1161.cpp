#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Định nghĩa cấu trúc cây nhị phân
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Hàm tìm mức có tổng giá trị lớn nhất
int maxLevelSum(TreeNode* root) {
    if(!root) return 0 ;
    queue<TreeNode*> q ;
    q.push(root);
    int maxSum = INT_MIN , level = 1 , minLevel = 1 ;
    while(!q.empty()){
        int levelSize = q.size();
        int sum = 0 ;
        for (int i = 0 ; i < levelSize ; i++){
            TreeNode* node = q.front();
            q.pop();
            sum+= node->val ;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        if(sum > maxSum){
            maxSum = sum ;
            minLevel = level ; 
        }
        level++;
    }
    return minLevel ; 
}

int main() {
    // Tạo cây ví dụ
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    
    cout << "Mức có tổng lớn nhất: " << maxLevelSum(root) << endl;
    
    return 0;
}
