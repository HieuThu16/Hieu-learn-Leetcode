#include <iostream>
#include <stack>

// Định nghĩa cấu trúc của một node trong danh sách liên kết
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Cách 1: Dùng con trỏ (Lặp - Iterative)
ListNode* reverseListIterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next; // Lưu node tiếp theo
        curr->next = prev; // Đảo chiều liên kết
        prev = curr;
        curr = next;
    }
    return prev;
}

// Cách 2: Đệ quy (Recursive)
ListNode* reverseListRecursive(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// Cách 3: Dùng Stack
ListNode* reverseListStack(ListNode* head) {
    if (!head) return nullptr;
    std::stack<ListNode*> nodeStack;
    ListNode* temp = head;
    
    while (temp) {
        nodeStack.push(temp);
        temp = temp->next;
    }
    
    ListNode* newHead = nodeStack.top();
    nodeStack.pop();
    temp = newHead;
    
    while (!nodeStack.empty()) {
        temp->next = nodeStack.top();
        nodeStack.pop();
        temp = temp->next;
    }
    temp->next = nullptr;
    
    return newHead;
}

// Hàm tiện ích để in danh sách liên kết
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Tạo danh sách liên kết: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    std::cout << "Danh sách ban đầu: ";
    printList(head);
    
    // Đảo ngược bằng phương pháp lặp
    head = reverseListIterative(head);
    std::cout << "Danh sách sau khi đảo ngược (Iterative): ";
    printList(head);
    
    // Đảo ngược lại bằng đệ quy
    head = reverseListRecursive(head);
    std::cout << "Danh sách sau khi đảo ngược (Recursive): ";
    printList(head);
    
    // Đảo ngược lại bằng stack
    head = reverseListStack(head);
    std::cout << "Danh sách sau khi đảo ngược (Stack): ";
    printList(head);
    
    return 0;
}
