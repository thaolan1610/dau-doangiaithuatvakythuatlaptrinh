class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy(0), largeDummy(0);

        ListNode* small = &smallDummy;
        ListNode* large = &largeDummy;

        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }

        // kết thúc list lớn
        large->next = nullptr;

        // nối 2 list
        small->next = largeDummy.next;

        return smallDummy.next;
    }
};