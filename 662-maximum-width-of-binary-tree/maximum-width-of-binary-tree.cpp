class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        int mx = 0;
        
        while (!q.empty()) {
            int s = q.size();
            unsigned long long f = 0, b = 0;
            unsigned long long offset = q.front().second;
            
            for (int i = 0; i < s; ++i) {
                auto k = q.front();
                q.pop();
                
                unsigned long long cur_index = k.second - offset; 
                
                if (i == 0) f = cur_index;
                if (i == s - 1) b = cur_index;
                
                if (k.first->left != nullptr) {
                    q.push({k.first->left, 2 * cur_index});
                }
                if (k.first->right != nullptr) {
                    q.push({k.first->right, 2 * cur_index + 1});
                }
            }
            mx = max(static_cast<int>(b - f + 1), mx);
        }
        return mx;
     }
};

