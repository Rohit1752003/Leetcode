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
    int find(vector<int>& postorder , int element){
        for(int i = 0 ; i < postorder.size() ; i++){
            if(postorder[i] == element)return i;
        }
        return -1;

    }
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder , int &preIndex , int start , int end){
        if(start > end)return nullptr;
        TreeNode* node = new TreeNode(preorder[preIndex++]);

        if(start == end)return node;
        int leftRoot = preorder[preIndex];
        int position = find(postorder  , leftRoot);
        node->left = solve(preorder , postorder , preIndex , start , position );
        node->right = solve(preorder , postorder , preIndex , position + 1 , end-1);
        return node;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int preIndex =0 ;
        return solve(preorder , postorder, preIndex , 0 , n-1);
    }
};