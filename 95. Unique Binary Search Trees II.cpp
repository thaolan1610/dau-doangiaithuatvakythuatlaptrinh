class Solution {
public:
    vector<TreeNode*> generate(int l, int r) {
        vector<TreeNode*> res;

        if (l > r) {
            res.push_back(nullptr);
            return res;
        }

        for (int i = l; i <= r; i++) {

            vector<TreeNode*> leftTrees = generate(l, i - 1);
            vector<TreeNode*> rightTrees = generate(i + 1, r);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {

                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;

                    res.push_back(root);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generate(1, n);
    }
};