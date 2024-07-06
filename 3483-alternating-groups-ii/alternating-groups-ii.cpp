class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count =1,last =colors[0],n=colors.size(), ans=0;
        for(int i=1;i<n;i++){
            count = (colors[i]!= last)?count+1:1;
            if(count >= k) ans++;
            last = colors[i];
        }
        for(int i=0;i<k-1;i++){
            count = (colors[i]!= last)?count+1:1;
            if(count >= k) ans++;
            last = colors[i];
        }
        return ans;
    }
};