class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2, r = nums.size()-1,k=-1;
        while(i>=0){
            if(nums[i+1] > nums[i]){
                k =r;
                while(nums[k] <= nums[i]){
                    k--;
                }
                swap(nums[k], nums[i]);
                reverse(nums.begin()+i+1,nums.end());
                break;
            }
            i--;
        }
        if(k == -1){
            reverse(nums.begin(),nums.end());
        }
    }
};