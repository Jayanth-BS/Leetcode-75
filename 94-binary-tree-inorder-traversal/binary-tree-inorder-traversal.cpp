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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;

        while(cur!= nullptr || !st.empty()){
            while(cur != nullptr){
                st.push(cur);
                cur =cur->left;
            }
        
            cur = st.top();
            ans.push_back(cur->val);
            st.pop();
            cur = cur->right;
        }
      
        return ans;  
    }
};