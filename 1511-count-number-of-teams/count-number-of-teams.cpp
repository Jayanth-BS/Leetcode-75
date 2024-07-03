class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> lsm(n+1,0);
        vector<int> rsm(n+1,0);
        vector<int> rlg(n+1,0);
        vector<int> llg(n+1,0);
        int ans=0;
        for(int i=0;i<n;i++){
            int ll=0,ls=0;
            int rl=0,rs=0;
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i])
                ls++;
                if(rating[j]>rating[i])
                ll++; 
            }
            lsm[i] = ls;
            llg[i] = ll;
            for(int j=i+1;j<n;j++){
                if(rating[j]<rating[i])
                rs++;
                if(rating[j]>rating[i])
                rl++; 
            }
            rsm[i] = rs;
            rlg[i] = rl;
        }

        for(int i=0;i<n;i++){
            ans += lsm[i]*rlg[i] +rsm[i]*llg[i];
        }
        return ans;
    }
};