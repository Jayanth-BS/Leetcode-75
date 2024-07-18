class Solution {
public:
    void f(int ind,vector<int>& c, int tgt, vector<int> &v, vector<vector<int>> &ans){
        if(tgt<0)
            return;
        if(ind == c.size() || tgt == 0){
            if(tgt == 0)
            ans.push_back(v);
            return;
        }

        for(int i=ind; i <= c.size()-1;i++){
            if(i!= ind  && c[i] == c[i-1] ||(tgt<c[ind])){
                continue;
            }
            v.push_back(c[i]);
            f(i+1,c,tgt-c[i],v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int tgt) {
        vector<int> v;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        f(0,candidates,tgt,v,ans);
        return ans ;
    }
};