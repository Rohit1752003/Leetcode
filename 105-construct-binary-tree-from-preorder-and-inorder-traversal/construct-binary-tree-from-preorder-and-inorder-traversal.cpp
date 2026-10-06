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
    int findPosition(vector<int> &inorder  , int element){
        for(int i = 0 ; i < inorder.size() ; i++){
            if(inorder[i] == element)return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder , int &preIndex , int start , int end ){
        if(start > end)return nullptr;
        TreeNode* node = new TreeNode(preorder[preIndex++]);
        int position = findPosition(inorder , node->val);

        node->left = solve(preorder , inorder , preIndex , start , position -1 );
        node->right = solve(preorder , inorder , preIndex , position + 1 , end);
        return node;
    }
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex =0;
        int n = preorder.size();
        return solve(preorder , inorder , preIndex , 0 , n-1);
    }
};