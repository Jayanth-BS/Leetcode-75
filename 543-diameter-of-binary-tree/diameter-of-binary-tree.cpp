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
    int f(TreeNode* root,int& dia){
        if(root == NULL)
        return 0;
        int l = f(root->left,dia);
        int r = f(root->right,dia);
        dia = max(dia,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root ==  NULL)
        return 0;
        int dia=0;
        f(root,dia);
        return dia;
    }
};