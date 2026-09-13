class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char c:s){
            if(c>='a' && c<='z'||c>='A' && c<='Z'){
                temp+=tolower(c);
            }else if(c>='0' && c<='9'){
                temp+=c;
            }
        }
        string temp1=temp;
        reverse(temp1.begin(),temp1.end());
        return temp1==temp;
    }
};