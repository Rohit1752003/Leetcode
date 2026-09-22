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
    vector<int> solve(TreeNode* root , vector<int> &ans){
        if(!root)return ans;
         solve(root->left ,ans);
        solve(root->right , ans);
       
        ans.push_back(root->val);
        return ans;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
        // if (!root) return ans;

     

        // // Traverse left subtree
        // vector<int> left = postorderTraversal(root->left);
        // ans.insert(ans.end(), left.begin(), left.end());

        // // Traverse right subtree
        // vector<int> right = postorderTraversal(root->right);
        // ans.insert(ans.end(), right.begin(), right.end());
        //    // Visit root first
        // ans.push_back(root->val);
        // return ans;


        return solve(root  ,ans);
    }
};