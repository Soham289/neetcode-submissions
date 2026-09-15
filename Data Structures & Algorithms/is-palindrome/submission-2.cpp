class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string temp;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
                temp.push_back(s[i]);
            }
        }
        int l=0,r=temp.size()-1;
        while(l<=r){
            if(tolower(temp[l++]) != tolower(temp[r--])) return false;
        }
        return true;
    }
};
