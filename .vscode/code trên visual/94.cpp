#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Định nghĩa cấu trúc node của cây nhị phân
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Hàm thực hiện duyệt inorder bằng stack
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* current = root;

    while (current != nullptr || !st.empty()) {
        // Đi hết nhánh trái
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // Lấy node trên cùng của stack
        current = st.top();
        st.pop();

        // Thêm giá trị của node vào kết quả
        result.push_back(current->val);

        // Chuyển sang nhánh phải
        current = current->right;
    }

    return result;
}

int main() {
    // Tạo một cây nhị phân ví dụ:
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Gọi hàm inorderTraversal
    vector<int> inorder = inorderTraversal(root);

    // In kết quả
    cout << "Inorder traversal: ";
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    // Giải phóng bộ nhớ (nếu cần)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
