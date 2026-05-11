class Solution {
public:
    vector<int> res;

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->left);     // Left
        res.push_back(root->val); // Root
        dfs(root->right);    // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};