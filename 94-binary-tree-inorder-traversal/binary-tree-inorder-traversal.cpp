class Solution {
    vector<int> solve(TreeNode* root , vector<int> &ans){
        if(!root)return ans;
        solve(root->left , ans);
        ans.push_back(root->val);
        solve(root->right ,ans);
        return ans;
        
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Iterative Approach 
      /*  stack<TreeNode*>st;
        TreeNode* node = root;
        vector<int> ans;
        while(true){
            if(node!=NULL){
                st.push(node->val);
                node= node->left;
            }
            else{
                if(st.empty()==true)break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node= node->right;
            }
        }
        
        vector<int> ans;
        if (!root) return ans;

        // Traverse left subtree
        vector<int> left = inorderTraversal(root->left);
        ans.insert(ans.end(), left.begin(), left.end());

        // Visit root
        ans.push_back(root->val);

        // Traverse right subtree
        vector<int> right = inorderTraversal(root->right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
        */

         vector<int> ans;
      
        return solve(root  , ans);
    }
};
