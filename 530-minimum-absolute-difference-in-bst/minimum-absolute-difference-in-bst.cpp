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
    void inorder(TreeNode* root , vector<int> &ans){
        if(!root)return ;

        inorder(root->left  , ans);
        ans.push_back(root->val);
        inorder(root->right , ans);
    }
public:
    int getMinimumDifference(TreeNode* root) {
       vector<int> ans;
       inorder(root  , ans);
        
        int minDiff = INT_MAX;
      
       for (int i = 1; i < ans.size(); i++) {
            minDiff = min(minDiff, ans[i] - ans[i - 1]);
        }
        //   int i = 0;
        // int j = 1;
        // while( i < ans.size() && j < ans.size()){
        //     minDiff = min(minDiff , abs(ans[i] - ans[j]));
        //     i++ , j++;
        // }
        return minDiff;
    }
};