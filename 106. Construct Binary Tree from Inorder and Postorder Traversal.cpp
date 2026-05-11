class Solution {
public:
    unordered_map<int, int> pos;
    int postIndex;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inLeft, int inRight) {

        if (inLeft > inRight) return NULL;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = pos[rootVal];

        // ⚠️ quan trọng: phải build right trước
        root->right = build(inorder, postorder, mid + 1, inRight);
        root->left  = build(inorder, postorder, inLeft, mid - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        postIndex = n - 1;

        return build(inorder, postorder, 0, n - 1);
    }
};