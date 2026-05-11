class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;

        dfs(root->left, res);   // Left
        dfs(root->right, res);  // Right
        res.push_back(root->val); // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};