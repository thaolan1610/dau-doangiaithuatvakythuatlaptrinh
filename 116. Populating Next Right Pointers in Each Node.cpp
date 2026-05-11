class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* leftmost = root;

        while (leftmost->left) {
            Node* cur = leftmost;

            while (cur) {
                // nối trái -> phải
                cur->left->next = cur->right;

                // nối phải -> trái của node kế bên
                if (cur->next)
                    cur->right->next = cur->next->left;

                cur = cur->next;
            }

            leftmost = leftmost->left;
        }

        return root;
    }
};