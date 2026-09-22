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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)return true;
        if((p!=NULL && q==NULL )||(p==NULL && q!= NULL))return false;
        // bool left = isSameTree(p->left,q->left);
        // bool right = isSameTree(p->right , q->right);
        // bool value = p->val == q->val;
        // if(left && right && value)return true;

        // return false;
        stack<pair<TreeNode* , TreeNode*>> st;
        
        st.push({p , q});
        while(!st.empty()){
            TreeNode* a = st.top().first;
            TreeNode* b = st.top().second;
            st.pop();
            if(!a && !b)continue;

            if(!a || !b)return false;

            if(a->val != b->val)return false;

            st.push({a->left , b->left});
            st.push({a->right , b->right}); 
        }
        return true;
    }
    
};