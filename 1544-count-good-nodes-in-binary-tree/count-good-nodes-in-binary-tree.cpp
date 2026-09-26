/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root , int maxSoFar){
        if(!root)return 0;
        int good =0;
        if(maxSoFar <= root->val){
            good += 1;
        }
        maxSoFar = max(maxSoFar  , root->val);
        return good + solve(root->left , maxSoFar) +
        solve(root->right ,maxSoFar);
    }
public:
    int goodNodes(TreeNode* root) {
         if (!root)
            return 0;
        return solve(root , root->val);
    }
};