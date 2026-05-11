class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;

        ListNode* dummy = new ListNode(0); // list đã sort
        ListNode* cur = head;

        while (cur) {
            ListNode* next = cur->next;

            ListNode* prev = dummy;

            // tìm vị trí chèn
            while (prev->next && prev->next->val < cur->val) {
                prev = prev->next;
            }

            // insert cur vào giữa prev và prev->next
            cur->next = prev->next;
            prev->next = cur;

            cur = next;
        }

        return dummy->next;
    }
};