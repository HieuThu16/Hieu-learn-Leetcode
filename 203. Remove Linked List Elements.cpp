#include <iostream>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to remove nodes with the given value
ListNode* removeElements(ListNode* head, int val) {
    // Create a dummy node to handle edge cases (e.g., removing head nodes)
    ListNode* dummy = new ListNode(0, head);
    ListNode* current = dummy;

    // Traverse the linked list
    while (current->next != nullptr) {
        if (current->next->val == val) {
            // Remove the node with value == val
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp; // Free the memory
        } else {
            // Move to the next node
            current = current->next;
        }
    }

    // Return the new head (skipping the dummy node)
    ListNode* newHead = dummy->next;
    delete dummy; // Free the memory of the dummy node
    return newHead;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

// Example usage
int main() {
    // Create a sample linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    cout << "Original list: ";
    printList(head);

    // Remove all nodes with value 6
    int val = 6;
    head = removeElements(head, val);

    cout << "Modified list: ";
    printList(head);

    return 0;
}
