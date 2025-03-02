#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Định nghĩa cấu trúc của node trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    if (!root) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int size = q.size();
        double sum = 0;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        result.push_back(sum / size);
    }
    
    return result;
}

// Hàm kiểm tra
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<double> averages = averageOfLevels(root);
    for (double avg : averages) {
        cout << avg << " ";
    }
    return 0;
}
