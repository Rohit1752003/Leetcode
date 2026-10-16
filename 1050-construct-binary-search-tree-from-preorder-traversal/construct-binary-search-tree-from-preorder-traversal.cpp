class Solution {
    int findPosition(vector<int>& pre, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
            if (pre[i] > pre[start]) {
                return i;
            }
        }
        return end + 1;
    }

    TreeNode* solve(vector<int>& preorder, int low, int high, int& preIndex) {
        if (low > high) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int position = findPosition(preorder, low, high);

        root->left = solve(preorder, preIndex, position - 1, preIndex);
        root->right = solve(preorder, position, high, preIndex);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preIndex = 0;
        return solve(preorder, 0, preorder.size() - 1, preIndex);
    }
};