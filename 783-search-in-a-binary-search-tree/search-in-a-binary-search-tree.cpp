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
   /* f(TreeNode* root,int val){
        if(root->val == val){
            return new TreeNode(root->val,root->left,root->right);
        }
        else if(root->val> val){
            f(root->left,val);
        }
        else{
            f(root->right,val);
        }
    }*/
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* cur;
        TreeNode* ans = nullptr;

        cur = root;
        while(cur!=nullptr){
            if(cur->val == val)
             {
                ans = cur;
                break;
             }
             else if(cur->val < val){
                cur= cur->right;
             }
             else
             cur = cur -> left;
        }
        return ans;
    }
};