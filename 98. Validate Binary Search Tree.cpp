class Solution {
public:
    bool dfs(TreeNode* root, long long low, long long high) {
        if (!root) return true;

        if (root->val <= low || root->val >= high)
            return false;

        return dfs(root->left, low, root->val) &&
               dfs(root->right, root->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};