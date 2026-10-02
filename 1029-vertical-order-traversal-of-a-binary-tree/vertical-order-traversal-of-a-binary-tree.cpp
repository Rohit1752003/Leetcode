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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans ;
        if(!root)return ans;
        map<int  , map<int , multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int , int>>> q;
        q.push({root , {0,0}});
        while(!q.empty()){
            pair<TreeNode* , pair<int , int>>temp = q.front();
            TreeNode* curr = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            q.pop();
            nodes[col][row].insert(curr->val);

            if(curr->left)q.push({curr->left , {row+1 , col-1}});
            if(curr->right)q.push({curr->right , {row + 1 , col + 1}});

        }
      for(auto i : nodes){
        vector<int> temp;
        for(auto j : i.second){
            for(auto k : j.second){
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
      }
      return ans;
    }
};