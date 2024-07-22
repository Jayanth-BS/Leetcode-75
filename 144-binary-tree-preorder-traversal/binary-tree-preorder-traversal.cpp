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
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> ans;
       TreeNode* cur = root;
        while(cur){
            if(cur->left == nullptr){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right!=nullptr && prev->right!= cur){
                    prev = prev->right;
                }
                if(prev->right == nullptr){
                    prev->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    prev->right = nullptr;
                    cur =cur->right;
                }
            }
        }
        return ans;
    }
};