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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2)return nullptr;
        if(!root1 && root2)return root2;
        if(root1 && !root2)return root1;

        TreeNode* node = new TreeNode(root1->val + root2->val);

        if(root1->left && root2->left){
            node->left = mergeTrees(root1->left , root2->left);

        }
        if(root1->left && !root2->left)node->left = mergeTrees(root1->left , nullptr);

        if(!root1->left && root2->left)node->left = mergeTrees( nullptr , root2->left);

        if(root1->right && root2->right){
            node->right = mergeTrees(root1->right , root2->right);

        }
        if(root1->right && !root2->right)node->right = mergeTrees(root1->right , nullptr);

        if(!root1->right && root2->right)node->right = mergeTrees( nullptr , root2->right);
        return node;
    }
};