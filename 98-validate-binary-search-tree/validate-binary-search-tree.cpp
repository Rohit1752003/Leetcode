class Solution {
public:
    bool isBST(TreeNode* root, long long min, long long max) {
        if (!root) return true;
        if (root->val <= min || root->val >= max) return false;

        bool left = isBST(root->left, min, root->val);
        bool right = isBST(root->right, root->val, max);

        return left && right;
    }
   /* void inorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    */

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
      /*
        vector<int> ans;
        inorder(root, ans);

        // check if inorder traversal is strictly increasing
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] <= ans[i - 1]) return false;
        }
        return true;
        */
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};
