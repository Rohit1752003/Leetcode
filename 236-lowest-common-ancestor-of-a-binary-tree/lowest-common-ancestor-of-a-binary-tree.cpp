class Solution {

    void solve(TreeNode* root,
               int p,
               int q,
               vector<int>& path,
               vector<int>& p1,
               vector<int>& q1) {

        if (!root)
            return;

        path.push_back(root->val);

        if (root->val == p)
            p1 = path;

        if (root->val == q)
            q1 = path;

        solve(root->left, p, q, path, p1, q1);
        solve(root->right, p, q, path, p1, q1);

        path.pop_back();
    }

public:

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {
        
        if(!root)return nullptr;
        if( root== p || root==q)return root;

       TreeNode* left =  lowestCommonAncestor(root->left , p , q);
      TreeNode* right =   lowestCommonAncestor(root->right , p , q);
        if (left && right)
        return root;

    if (left)
        return left;

    return right;

        
        // vector<int> path;
        // vector<int> p1;
        // vector<int> q1;

        // solve(root, p->val, q->val, path, p1, q1);

        // int ans = -1;

        // int i = 0;

        // while (i < p1.size() && i < q1.size()) {

        //     if (p1[i] != q1[i])
        //         break;

        //     ans = p1[i];
        //     i++;
        // }

        // // Find the actual node having this value
        // queue<TreeNode*> qu;
        // qu.push(root);

        // while (!qu.empty()) {

        //     TreeNode* curr = qu.front();
        //     qu.pop();

        //     if (curr->val == ans)
        //         return curr;

        //     if (curr->left)
        //         qu.push(curr->left);

        //     if (curr->right)
        //         qu.push(curr->right);
        // }

        // return nullptr;
    }
};