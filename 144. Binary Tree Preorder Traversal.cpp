class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;

        res.push_back(root->val); // Root
        dfs(root->left, res);     // Left
        dfs(root->right, res);    // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};