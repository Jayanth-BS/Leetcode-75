class Solution {
public:
    int f(vector<int> nums, int k){
        int i=0,j=0;
        int sum=0,m=0;
        while(j<nums.size()){
            sum += nums[j]%2;
            while(sum > k){
                sum -= nums[i]%2;
                i++;
            }
            m = m+(j-i+1);
            j++;
        }
        return m;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x=0;
        return f(nums,k)-f(nums,k-1);
    }
};