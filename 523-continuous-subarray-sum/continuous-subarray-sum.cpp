class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = -1;
        long sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            sum = sum%k;
            if(map.count(sum)){
            if(i - map[sum]>1)
            return 1;
            }
            else
            map[sum] = i;
        }
        return 0;
     }
};