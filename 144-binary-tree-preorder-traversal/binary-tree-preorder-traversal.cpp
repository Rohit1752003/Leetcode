class Solution {
     vector<int>  solve(TreeNode* root , vector<int>& ans){
    if(!root)return ans;

    ans.push_back(root->val);
    if(root->left)
    solve(root->left , ans);

        if(root->right)
    solve(root->right , ans);
    return ans;
   }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // if (!root) return ans;

        // // Visit root first
        // ans.push_back(root->val);

        // // Traverse left subtree
        // vector<int> left = preorderTraversal(root->left);
        // ans.insert(ans.end(), left.begin(), left.end());

        // // Traverse right subtree
        // vector<int> right = preorderTraversal(root->right);
        // ans.insert(ans.end(), right.begin(), right.end());

        // return ans;

        // 2Nd Approch
        //  if(!root )return ans ;

        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     TreeNode* node = st.top();
        //     st.pop();
        //     ans.push_back(node->val);
        //     if(node->right)st.push(node->right);
        //      if(node->left)st.push(node->left);

        // }

        // 3rd Approach

        return solve(root , ans);
        // return ans;
    }
};
