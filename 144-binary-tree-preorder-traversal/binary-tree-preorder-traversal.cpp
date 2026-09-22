class Solution {
   
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


         if(!root )return ans ;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right)st.push(node->right);
             if(node->left)st.push(node->left);

        }
        return ans;
    }
};
