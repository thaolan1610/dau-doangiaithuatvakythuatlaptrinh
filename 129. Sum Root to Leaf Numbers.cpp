class Solution {
public:

    int dfs(TreeNode* root, int current) {

        if (!root) return 0;

        // tạo số mới
        current = current * 10 + root->val;

        // leaf node
        if (!root->left && !root->right) {
            return current;
        }

        // tổng trái + phải
        return dfs(root->left, current) +
               dfs(root->right, current);
    }

    int sumNumbers(TreeNode* root) {

        return dfs(root, 0);
    }
};