#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;

        int sum = x + y + carry;
        carry = sum / 10;

        tail->next = new ListNode(sum % 10);
        tail = tail->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val;
        if (head->next != nullptr) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create first number: 342
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));

    // Create second number: 465
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print result: should be 7 -> 0 -> 8 (807)
    printList(result);

    return 0;
}
