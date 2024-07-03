class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<4){
            return 0;
        }
        int mini =INT_MAX;
        for(int left=0,right =nums.size()-4;left<4;left++,right++){
            mini = min(mini,nums[right]-nums[left]);
        }
        return mini;
    }
};