class Solution {
public:
    string compressedString(string word) {
        string cmp="";
        int i=0;
        while(i<word.size()){
            int cnt=0;
            char c = word[i];
            while(i<word.size() && c == word[i] && cnt<9){
                i++;
                cnt++;
            }
            cmp += to_string(cnt)+c;
        }
        return cmp;
    }
};