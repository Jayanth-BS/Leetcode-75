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
        unordered_map<int,TreeNode*> map;
        for(auto d: descriptions){
            map[d[1]] = new TreeNode(d[1]);
        }
        TreeNode* root=nullptr;
        for(auto d:descriptions){
            if(!map[d[0]]){
                map[d[0]] = new TreeNode(d[0]);
                root = map[d[0]];
                break;
            }
        }
        for(auto d: descriptions){
            if(d[2]) map[d[0]]->left = map[d[1]];
            else map[d[0]]->right = map[d[1]];
        }
        return root;
    }
};