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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<pair<int,int>>> map;
        set<int> par, child;
        for(auto i:descriptions){
            map[i[0]].push_back({i[1],i[2]});
            par.insert(i[0]);
            child.insert(i[1]);
        }
        int val ;
        for(auto i:par){
                if(!child.count(i)){
                    val = i;
                }
        }
        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front(); q.pop();
            for(auto i: map[temp->val]){
                 TreeNode* node = new TreeNode(i.first);
                if(i.second == 1)
                    temp->left = node;
                
                if(i.second == 0)
                     temp->right = node;
                
                q.push(node);
            }
        }
        return root;
    }
};