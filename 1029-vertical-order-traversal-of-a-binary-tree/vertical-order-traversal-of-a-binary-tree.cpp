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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        return ans;
        map<int,vector<pair<int,int>>> map;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            TreeNode* node = it.first;
            int hd = it.second.first;
            int l= it.second.second;
            map[hd].push_back({l,node->val});
            q.pop();
            if(node->left)
            q.push({node->left, {hd-1, l+1}});
            if(node->right)
            q.push({node->right, {hd+1, l+1}});
            
        }
        for(auto it :map){
            vector<int> v;
            sort(it.second.begin(), it.second.end());
            for(auto val : it.second)
            v.push_back(val.second);
            ans.push_back(v);
        }
        return ans;
    }
};