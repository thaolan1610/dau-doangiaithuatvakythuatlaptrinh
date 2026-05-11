class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // nếu là leaf
        if (!root->left && !root->right)
            return targetSum == root->val;

        int remain = targetSum - root->val;

        return hasPathSum(root->left, remain) ||
               hasPathSum(root->right, remain);
    }
};