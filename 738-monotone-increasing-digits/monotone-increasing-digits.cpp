class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> v;
        int m = n;
        while(m!=0){
            v.push_back(m % 10);
            m = m/10;
        }
        
        reverse(v.begin(),v.end());
        for(int i=v.size()-1;i>0;i--){
            if(v[i-1]>v[i]){
                v[i-1]-=1;
                cout<<'h';
                int j=i;
                while(j<=v.size()-1){
                    v[j] = 9;
                    j++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans = 10*ans +v[i];
        }
        return ans;
    }
};