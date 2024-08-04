class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sum;
        for(int i=0;i<n;i++){
            long long s=0;
            for(int j=i;j<n;j++){
                s += nums[j];
                sum.push_back(s);
            }
        } 
        long long s =0;
        sort(sum.begin(), sum.end());
        for(int i=left-1;i<=right-1;i++){
            s= (s+sum[i])%1000000007;
        }  
        return s;
    }
};