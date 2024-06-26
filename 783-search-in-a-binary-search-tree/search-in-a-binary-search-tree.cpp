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
    TreeNode* f(TreeNode* root,int val){
        if(root == nullptr|| root->val == val)
        return root;
        else if(root->val> val){
            return f(root->left,val);
        }
        else {
           return f(root->right,val);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return f(root,val);
    }
};