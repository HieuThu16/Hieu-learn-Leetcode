#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Định nghĩa cấu trúc của một node trong cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm trả về danh sách các giá trị nhìn thấy từ bên phải
vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if(!root) return result ;
    queue<TreeNode*> q ;
    q.push(root);
    while(!q.empty()){
        int level = q.size();
        TreeNode* rightNode = nullptr ;
        for(int i = 0 ; i < level ; i++){
            TreeNode* node = q.front();
            q.pop();
            rightNode = node ;
            if(node -> left) q.push(node->left);
            if(node -> right) q.push(node->right);
        }
        result.push_back(rightNode->val);
    }
    return result ;
}

// Hàm tạo cây và kiểm tra kết quả
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> visibleNodes = rightSideView(root);

    cout << "Cac gia tri nhin thay tu ben phai: ";
    for (int val : visibleNodes) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
