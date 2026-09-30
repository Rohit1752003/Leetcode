/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode* , TreeNode*> mp;
          parentMatching(root , mp );
            unordered_map<TreeNode* , bool> vis;
          queue<TreeNode*> q;
          q.push(target);
          vis[target]= true;
          int curr_level = 0;
          while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k)break;
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
          }
          vector<int> ans;
          while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
          }
          return ans;

    }
};