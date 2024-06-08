class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> s;
        for(auto i: dictionary)
            s.insert(i);
        
        string ans;
        int i=0,f=1;
        while(i<sentence.size()){
            int j=i;
            f=1;
            int k=0;
            while(sentence[j] != ' ' && sentence[j]!='\0'){

                if(f==1 && s.count(sentence.substr(i,j-i+1))){
                    f=0;
                    ans += sentence.substr(i,j-i+1);
                    //ans += ' ';
                }
                j++;
            }
            if(f==1){
                ans+= sentence.substr(i,j-i);
            }
            if(sentence[j]!='\0')
           ans+=' ';
            i = j+1;
        }
       // ans.pop_back();
        return ans;
    }
};