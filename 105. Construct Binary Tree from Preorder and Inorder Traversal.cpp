class Solution {
public:
    unordered_map<int, int> pos;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int inLeft, int inRight) {

        if (inLeft > inRight) return NULL;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];

        root->left = build(preorder, inorder, inLeft, mid - 1);
        root->right = build(preorder, inorder, mid + 1, inRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        return build(preorder, inorder, 0, n - 1);
    }
};