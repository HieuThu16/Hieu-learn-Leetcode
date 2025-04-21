#include <iostream>  
#include <queue>  

using namespace std;  

// Definition for a binary tree node  
struct TreeNode {  
    int val;  
    TreeNode *left;  
    TreeNode *right;  
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
};  

// Recursive approach to check if the tree is symmetric  
bool isMirror(TreeNode* left, TreeNode* right) {  
    if (left == nullptr && right == nullptr) {  
        return true;  
    }  
    if (left == nullptr || right == nullptr) {  
        return false;  
    }  
    return (left->val == right->val)   
        && isMirror(left->right, right->left)   
        && isMirror(left->left, right->right);  
}  

bool isSymmetricRecursive(TreeNode* root) {  
    return isMirror(root, root);  
}  

// Iterative approach to check if the tree is symmetric  
bool isSymmetricIterative(TreeNode* root) {  
    if (root == nullptr) return true;  

    queue<TreeNode*> q;  
    q.push(root->left);  
    q.push(root->right);  

    while (!q.empty()) {  
        TreeNode* left = q.front(); q.pop();  
        TreeNode* right = q.front(); q.pop();  

        if (left == nullptr && right == nullptr) {  
            continue;  
        }  
        if (left == nullptr || right == nullptr) {  
            return false;  
        }  
        if (left->val != right->val) {  
            return false;  
        }  

        q.push(left->left);  
        q.push(right->right);  
        q.push(left->right);  
        q.push(right->left);  
    }  

    return true;  
}  

// Helper function to create a binary tree from an array  
TreeNode* createTree(const vector<int>& nodes) {  
    if (nodes.empty()) return nullptr;  

    TreeNode** nodeArray = new TreeNode*[nodes.size()];  
    for (size_t i = 0; i < nodes.size(); ++i) {  
        if (nodes[i] != NULL) {  
            nodeArray[i] = new TreeNode(nodes[i]);  
        } else {  
            nodeArray[i] = nullptr;  
        }  
    }  
    for (size_t i = 0; i < nodes.size(); ++i) {  
        if (nodeArray[i] != nullptr) {  
            int leftIndex = 2 * i + 1;  
            int rightIndex = 2 * i + 2;  
            if (leftIndex < nodes.size()) {  
                nodeArray[i]->left = nodeArray[leftIndex];  
            }  
            if (rightIndex < nodes.size()) {  
                nodeArray[i]->right = nodeArray[rightIndex];  
            }  
        }  
    }  
    TreeNode* root = nodeArray[0];  
    delete[] nodeArray; // Clean up  
    return root;  
}  

int main() {  
    // Example 1: Symmetric tree  
    vector<int> nodes1 = {1, 2, 2, 3, 4, 4, 3};  
    TreeNode* root1 = createTree(nodes1);  
    cout << "Is the first tree symmetric (Recursive)? "   
         << (isSymmetricRecursive(root1) ? "True" : "False") << endl;  
    cout << "Is the first tree symmetric (Iterative)? "   
         << (isSymmetricIterative(root1) ? "True" : "False") << endl;  

    // Example 2: Non-symmetric tree  
    vector<int> nodes2 = {1, 2, 2, NULL, 3, NULL, 3};  
    TreeNode* root2 = createTree(nodes2);  
    cout << "Is the second tree symmetric (Recursive)? "   
         << (isSymmetricRecursive(root2) ? "True" : "False") << endl;  
    cout << "Is the second tree symmetric (Iterative)? "   
         << (isSymmetricIterative(root2) ? "True" : "False") << endl;  

    // Free allocated memory for trees (Note: Memory management not shown for simplicity)  
    delete root1; // In a real code, you would implement a proper destructor  
    delete root2; // In a real code, you would implement a proper destructor  

    return 0;  
}  