class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        long long ans =0;
        int x=1, y=1;
        int a= h.size()-1, b = v.size()-1;

        sort(v.begin(), v.end());
        sort(h.begin(), h.end());

        while(a>=0 && b>=0){
            if(v[b]> h[a]){
                x++;
                ans += v[b]*y;
                b--;
            }
            else{
                y++;
                ans += h[a]*x;
                a--;
            }
        }
        while(a >= 0){
            ans += h[a]*x;
            a--;
        } 
        while(b>= 0){
            ans += v[b]*y;
            b--;
        } 
        return ans;
    }
};