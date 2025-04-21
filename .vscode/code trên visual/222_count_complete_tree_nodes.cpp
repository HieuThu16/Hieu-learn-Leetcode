// Giải thích đề 


// complete binary tree , return the number of the node
// in the tree



#include <cmath> // dùng cho pow()

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Hàm phụ để tính chiều cao cây theo hướng trái hoặc phải
    int getHeight(TreeNode* node, bool goLeft) {
        int height = 0;
        while (node) {
            height++;
            node = goLeft ? node->left : node->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);

        if (leftHeight == rightHeight) {
            // Cây hoàn chỉnh, có thể tính trực tiếp: 2^h - 1
            return pow(2, leftHeight) - 1;
        } else {
            // Không hoàn chỉnh, đếm từng phần
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
