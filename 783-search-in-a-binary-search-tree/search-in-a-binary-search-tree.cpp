class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;     // base case
        if (root->val == val) return root;       // found
        if (val < root->val)
            return searchBST(root->left, val);  // go left
        else
            return searchBST(root->right, val); // go right
    }
};
