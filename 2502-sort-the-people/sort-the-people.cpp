class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> map;
        for(int i=0;i<names.size();i++){
            map[heights[i]] = names[i];
        }
        vector<string> ans;
        for(auto i = map.begin();i!= map.end();i++){
            ans.push_back(i->second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};