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
       stack<TreeNode*>st;
        TreeNode* curr = root;
        vector<int> ans;
        while (curr != nullptr || !st.empty()) {

            // Go as far left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // Left is finished → process root
            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            // Now explore right subtree
            curr = curr->right;
        }
        /*
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


//     3rd Approach
        //  vector<int> ans;
      
        // return solve(root  , ans);

        return ans;
    }
};
