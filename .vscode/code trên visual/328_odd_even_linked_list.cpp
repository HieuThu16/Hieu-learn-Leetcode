#include <iostream>
using namespace std;

// Định nghĩa cấu trúc danh sách liên kết
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Hàm nhóm các node lẻ và chẵn
ListNode* oddEvenList(ListNode* head) {
    if(!head || head->next) return head;
    ListNode* odd = head ;
    ListNode* even = head ->next;
    ListNode* evenHead = even ;
    while(even && even->next){
        odd->next = even->next;
        odd=odd->next ;
        even->next = odd->next ;
        even = even->next ;

    }
    odd->next = evenHead;
    return head; 
}

// Hàm in danh sách liên kết
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Tạo danh sách liên kết ví dụ
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Danh sách gốc: ";
    printList(head);
    
    head = oddEvenList(head);
    
    cout << "Danh sách sau khi nhóm: ";
    printList(head);
    
    return 0;
}
