class Solution {
public:
    vector<vector<string>> ans;
    bool is_palin(string s){
        for(int i=0;i<s.size()/2;i++)
            if(s[i] != s[s.size()-i-1])
                return 0;
        return 1;
    }

    void find(string s,int i, vector<string>& l){
        if(s.size()==0){
        ans.push_back(l);
        return;
        }
        for(int j=1;j<=s.size();j++){
            if(!is_palin(s.substr(0,j))){
           
            continue;
            }
             
            l.push_back(s.substr(0,j));
            find(s.substr(j,s.size()),j,l);
            l.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> l;
        find(s,0,l);
        return ans;
    }
};