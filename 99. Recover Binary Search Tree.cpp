class Solution {
public:
    TreeNode *first = NULL, *second = NULL, *prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // check violation
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;   // node sai đầu tiên
            }
            second = root;      // node sai thứ hai
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};