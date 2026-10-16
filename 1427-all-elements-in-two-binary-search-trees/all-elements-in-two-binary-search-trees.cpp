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
    void inorder(TreeNode* root , vector<int>& ans){
        if(!root)return ;

        inorder(root->left  , ans);
        ans.push_back(root->val);
        inorder(root->right  , ans);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1 , ans2 , ans;
        inorder(root1  , ans1 );
        inorder(root2  , ans2);
         int n = ans1.size() ; 
         int  m = ans2.size();
        int l =  0  , r =0 ;
        while(l < n && r < m){
            if(ans1[l] > ans2[r] ){
                ans.push_back(ans2[r]);
                r++;
            } 
            else if ( ans1[l] < ans2[r]){
                ans.push_back(ans1[l]);
                l++;
            }
            else {
                ans.push_back(ans1[l]);
                ans.push_back(ans2[r]);
                l++  , r++;
            }
        }
        while( l < n){
            ans.push_back(ans1[l]);
            l++;
        }
        while(r < m){
            ans.push_back(ans2[r]);
            r++;
        }
        return ans;
    }
};