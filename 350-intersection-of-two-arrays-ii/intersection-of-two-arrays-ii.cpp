class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        for(auto i: nums1)
        map[i]++;
        vector<int> v;
        for(int i=0;i<nums2.size();i++){
            if(map.count(nums2[i])){
                v.push_back(nums2[i]);
                map[nums2[i]]--;
                if(map[nums2[i]]==0)
                map.erase(nums2[i]);
            }
        }
        return v;
    }
};