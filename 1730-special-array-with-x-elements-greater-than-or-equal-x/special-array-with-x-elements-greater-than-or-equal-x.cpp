class Solution {
public:
    int specialArray(vector<int>& nums) {
       for(int i=0;i<=*max_element(nums.begin(),nums.end());i++){
        int f = i,c=0;    
        for(int j=0;j<nums.size();j++){
            if(nums[j]>=f)
            c++;
        }
        if(c == f)
        return c;
       }
        return -1;
    }
};