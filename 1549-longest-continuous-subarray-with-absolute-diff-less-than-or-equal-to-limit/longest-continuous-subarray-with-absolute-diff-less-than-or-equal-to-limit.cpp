class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> maxi, mini;
        int i=0, res=0;
        for(int j=0; j<nums.size(); j++){
            while(!maxi.empty() && maxi.back()<nums[j])
                maxi.pop_back();
            while(!mini.empty() && mini.back()>nums[j])
                mini.pop_back();
            
            maxi.push_back(nums[j]);
            mini.push_back(nums[j]);

            while(maxi.front()-mini.front() > limit){
                if(nums[i] == maxi.front())
                    maxi.pop_front();
                if(nums[i] == mini.front())
                    mini.pop_front();
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};