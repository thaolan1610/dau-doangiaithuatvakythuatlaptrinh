class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;

        path.push_back(root->val);

        // nếu là leaf
        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                res.push_back(path);
            }
        } 
        else {
            dfs(root->left, targetSum - root->val);
            dfs(root->right, targetSum - root->val);
        }

        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};