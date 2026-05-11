class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                // bỏ node trùng
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};