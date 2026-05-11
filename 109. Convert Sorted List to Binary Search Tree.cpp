class Solution {
public:
    ListNode* cur;

    int getSize(ListNode* head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    TreeNode* build(int l, int r) {
        if (l > r) return NULL;

        int mid = (l + r) / 2;

        TreeNode* left = build(l, mid - 1);

        TreeNode* root = new TreeNode(cur->val);
        cur = cur->next;

        root->left = left;
        root->right = build(mid + 1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        cur = head;
        int n = getSize(head);

        return build(0, n - 1);
    }
};