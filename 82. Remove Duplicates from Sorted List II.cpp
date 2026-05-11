class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* cur = head;

        while (cur) {
            // nếu có nhóm trùng
            if (cur->next && cur->val == cur->next->val) {
                int val = cur->val;

                // bỏ hết nhóm trùng
                while (cur && cur->val == val) {
                    ListNode* temp = cur;
                    cur = cur->next;
                    delete temp;
                }

                // nối lại (prev không di chuyển)
                prev->next = cur;
            }
            else {
                // không trùng → giữ lại
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy.next;
    }
};