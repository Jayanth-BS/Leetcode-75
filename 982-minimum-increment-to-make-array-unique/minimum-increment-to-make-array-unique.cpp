class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev = nums[0],sum=0;
        for(int i=0;i<nums.size();i++){
            sum += max(0,prev-nums[i]);
            prev = max(prev,nums[i])+1;
        }
        return sum;
    }
};