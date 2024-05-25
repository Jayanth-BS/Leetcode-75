class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> f;
        map<int,int> color;
        vector<int> ans;
        for(auto i:queries){
            int x = i[0];
            int y = i[1];
            if(color.count(x)){
                f[color[x]]--;
                if(f[color[x]] == 0) f.erase(color[x]); 
            }
            color[x] = y;
            f[color[x]]++;
            ans.push_back(f.size());
        }
        return ans;
    }
};