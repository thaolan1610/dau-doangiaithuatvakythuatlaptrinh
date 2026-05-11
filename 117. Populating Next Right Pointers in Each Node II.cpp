class Solution {
public:
    Node* connect(Node* root) {
        Node* cur = root;

        while (cur) {

            Node dummy(0);
            Node* tail = &dummy;

            while (cur) {

                if (cur->left) {
                    tail->next = cur->left;
                    tail = tail->next;
                }

                if (cur->right) {
                    tail->next = cur->right;
                    tail = tail->next;
                }

                cur = cur->next;
            }

            cur = dummy.next;
        }

        return root;
    }
};