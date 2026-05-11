class Solution {
public:

    int ans = INT_MIN;

    int dfs(TreeNode* root) {

        if (!root) return 0;

        // gain từ trái
        int leftGain = max(0, dfs(root->left));

        // gain từ phải
        int rightGain = max(0, dfs(root->right));

        // path đi qua node hiện tại
        int currentPath = root->val + leftGain + rightGain;

        // cập nhật đáp án
        ans = max(ans, currentPath);

        // trả về cho parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {

        dfs(root);

        return ans;
    }
};