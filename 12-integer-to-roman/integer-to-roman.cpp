class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> map;
        int n[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string val[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        int i=12;
        string ans;
        while(i>=0 && num != 0){
            while(num >= n[i]){
                num -= n[i];
                ans += val[i];
            }
            i--;
        }
        return ans;
    }
};