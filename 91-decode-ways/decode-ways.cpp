class Solution {
public:
    int t[101];

    int numDecodings(string s) {
        memset(t,-1,sizeof(t));
        int n = s.size();
        t[n] = 1;
        for(int i= n-1;i>=0;i--){
            if(s[i]=='0')
            t[i] = 0;
            else{
                t[i] = t[i+1];
                if(i+1<n)
        if(s[i]=='1' || s[i]=='2' && s[i+1]<='6'){
            t[i] += t[i+2];
        }
            }
        }
        return t[0];
        
    }
};