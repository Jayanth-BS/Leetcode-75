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
    vector<vector<int>> levelOrder(TreeNode* root) {
               vector<vector<int>> ans;
        if(root == nullptr)
        return ans;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty())
        {
        int s = q.size();
        vector<int> k;
        for(int i=0;i<s;i++){
            TreeNode* rooot = q.front();
            if(rooot->left!= NULL)
            q.push(rooot->left);
            if(rooot->right!= NULL)
            q.push(rooot->right);
            k.push_back(rooot->val);
            q.pop();
        }
        ans.push_back(k);
        }
        return ans;
    }
};