class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int l=0,r=0;
        while(l<word.size() && r<abbr.size()){
            if(isdigit(abbr[r])){
                if(abbr[r]=='0') return false;
                int num=0;
                while(r<abbr.size() && isdigit(abbr[r])){
                    num = num*10+(abbr[r]-'0');
                    r++;
                }
                l+=num;
            }else{
                if(word[l]!=abbr[r]) return false;
                l++;
                r++;
            }
        }
        return l==word.size() && r==abbr.size();
    }
};