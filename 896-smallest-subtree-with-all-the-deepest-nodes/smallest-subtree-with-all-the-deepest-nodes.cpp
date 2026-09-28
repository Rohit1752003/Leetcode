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
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;

        if (left)
            return left;

        return right;
    }


  
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
   queue<TreeNode*> q;
        q.push(root);

        vector<TreeNode*> deepest;

        while (!q.empty()) {

            int size = q.size();

            deepest.clear();

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                deepest.push_back(node);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }
        }
        // TreeNode* lca = deepest[0];

        // for (int i = 1; i < deepest.size(); i++) {
        //     lca = lowestCommonAncestor(root, lca, deepest[i]);
        // }
        
         // Or

        //  LCA has Property like if there are multiple nodes for lca the first and last node are consider to compute lca
        int n = deepest.size();
       TreeNode* lca =  lca = lowestCommonAncestor(root, deepest[0], deepest[n-1]);
        return lca;
        
    }
};