class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if(sequence.size()< word.size()) return 0;
        int mx =0 ;
        int c=0;
        for(int i=0;i<=sequence.size()-word.size();i++){
            if(sequence.substr(i,word.size()) == word){
                c++;
                i += word.size()-1;
            }
            else{
                if(c){
                mx=max(c,mx);
                i-=word.size()-1;
                c=0;
                }
            }
        }
        mx  = max(mx,c);
        return mx;
    }
};