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
    void solve(TreeNode* root , string path , long long &ans){
        if(!root)return ;

        path += to_string(root->val);
        if (!root->left && !root->right) {
          ans += stoll(path);
        }
        solve(root->left , path, ans);
        solve(root->right , path , ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        long long ans = 0;
        solve(root , "" , ans);
        return ans;
    }
};