class Solution {
public:
    int specialArray(vector<int>& nums) {
        int l = 0, h = nums.size();
        sort(nums.begin(),nums.end());
        while(l<=h){
            int mid = (l+h)/2, c=0;
            for(auto i: nums){
                if(i>=mid){
                    c++;
                }
            }
            if(c == mid)
            return c;

            else if(c>mid)
            l++;
            else
            h--; 
        }
        return -1;
    }
};