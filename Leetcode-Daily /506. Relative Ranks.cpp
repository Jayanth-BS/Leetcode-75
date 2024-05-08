//Return an array answer of size n where answer[i] is the rank of the ith athlete.

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        int max;
        vector<string> ans(n);
        for(int i=0;i<n;i++){
            max = i;
            for(int j=0;j<n;j++){
                if(score[j]>score[max])
                max = j;
            }
            score[max]=-1;

            if(i == 0)
            ans[max] = "Gold Medal";
            else if (i==1)
            ans[max] = "Silver Medal";
            else if (i==2)
            ans[max] = "Bronze Medal";
            else 
            ans[max] = to_string(i+1);
        }
        return ans;
    }
};
