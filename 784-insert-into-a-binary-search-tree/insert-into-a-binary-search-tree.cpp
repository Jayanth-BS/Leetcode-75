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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *cur,*prev;
        cur = root;
        while(cur != nullptr){
           if(val> cur->val){
                prev = cur;
                cur = cur->right;
            }
            else{
                prev = cur;
                cur = cur->left;
            }
        }
                TreeNode *ptr = new TreeNode(val);
         if(root == nullptr)
         return ptr;
                if(val > prev->val)
                prev->right = ptr;
                else
                prev->left = ptr;
            
        return root;
    }
};