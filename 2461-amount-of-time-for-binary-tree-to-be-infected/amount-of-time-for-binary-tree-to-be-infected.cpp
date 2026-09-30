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
      void parentMatching(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &mp  ){
        if(!root)return  ;
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            mp[ curr->left] =curr;
            q.push(curr->left);
        }
        if(curr->right){
            mp[curr->right] =curr ;
            q.push(curr->right);
        }
       }
    }
      TreeNode* solve(TreeNode* root , int target){
        if(!root)return nullptr;
        if(root->val == target)return root;
        TreeNode* left = solve(root->left , target);
        if(left)return left;
        return solve(root->right , target);
      }
public:
    int amountOfTime(TreeNode* root, int start) {
         unordered_map<TreeNode* , TreeNode*> mp;
          parentMatching(root , mp );
            unordered_map<TreeNode* , bool> vis;
          queue<TreeNode*> q;
          TreeNode* target = solve(root , start);
          q.push(target);
          vis[target]= true;
          int curr_level = 0;
          while(!q.empty()){
            int size = q.size();
         
            for(int i =0 ; i < size ; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left] ){
                        vis[curr->left] = true;
                        q.push(curr->left);
                }
                 if(curr->right && !vis[curr->right] ){
                        vis[curr->right] = true;
                        q.push(curr->right);
                }
                if(mp[curr] && !vis[mp[curr]]){
                    vis[mp[curr]] = true;
                    q.push(mp[curr]);
                }
            }
             curr_level +=1;
          }
         return curr_level-1;
    }
};