class Solution {
public:
    bool isPalindrome(int x) {
        string m = to_string(x);
        string u=m;
        reverse(m.begin(),m.end());
        return m==u;
    }
};