#include <iostream>
using namespace std;
// Định nghĩa cấu trúc của một node trong danh sách liên kết
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Hàm xóa node giữa của danh sách liên kết
ListNode* deleteMiddle(ListNode* head) {
    // Trường hợp đặc biệt: Nếu danh sách chỉ có một phần tử, trả về nullptr
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }
    
    // Sử dụng hai con trỏ: slow và fast để tìm node giữa
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    
    // Duyệt danh sách, slow đi một bước, fast đi hai bước
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Xóa node giữa
    prev->next = slow->next;
    delete slow;
    
    return head;
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
    
    std::cout << "Danh sach ban dau: ";
    printList(head);
    
    head = deleteMiddle(head);
    
    std::cout << "Danh sach sau khi xoa node giua: ";
    printList(head);
    
    return 0;
}
