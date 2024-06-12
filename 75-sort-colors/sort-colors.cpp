class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch flag algorithm
        const char red=0,white=1,blue=2;
        int l=0,m =0,r=nums.size()-1;
        while(m<=r){
            switch(nums[m]){
                case red:
                swap(nums[l],nums[m]);
                m++;
                l++;
                break;
                case white:
                m++;
                break;
                case blue:
                swap(nums[m],nums[r]);
                r--;
                break;
            }
        }   
    }
};