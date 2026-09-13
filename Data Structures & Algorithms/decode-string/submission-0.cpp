class Solution {
public:
    string decodeString(string s) {
        stack<int> numst;
        stack<string> strst;
        string cur;
        int num=0;
        for(char c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(c=='['){
                numst.push(num);
                strst.push(cur);
                num=0;
                cur="";
            }
            else if(c==']'){
                int repeat = numst.top(); numst.pop();
                string temp = cur;
                cur = strst.top(); strst.pop();
                while(repeat--){
                    cur+=temp;
                }
            }
            else{
                cur += c;
            }
        }
        return cur;
    }
};