//In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative
//Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.

 
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        int n = h.size();
        long long sum =0;
        sort(h.begin(),h.end());
        for(int i=0;i<n;i++){
            if(k-- && h[n-i-1]-i > 0)
            sum += h[n-i-1]-i;
            else 
            break;
        }
        return sum;
    }
};
