class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2)
        return nums;
        vector<int> ans;
        unordered_map<int,int> map;
        for(auto i: nums)
        map[i]++;
        for(auto i : map){
            if(i.second == 1)
            ans.push_back(i.first);
    }
    return ans;
    }
};