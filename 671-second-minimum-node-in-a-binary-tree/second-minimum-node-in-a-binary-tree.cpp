class Solution {
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        sort(ans.begin(), ans.end());

        int n = ans.size();

        if (n < 2) return -1;

        int minimum = ans[0];

        for (int i = 1; i < n; i++) {
            if (ans[i] > minimum) {
                return ans[i];
            }
        }

        return -1;
    }
};