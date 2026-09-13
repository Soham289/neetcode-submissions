class Solution {
public:
    int characterReplacement(string s, int k) {
       int maxcount=0,left=0,maxlen=0;
       unordered_map<char,int> count;
       for(int right=0;right<s.size();right++){
        count[s[right]]++;
        maxcount=max(maxcount,count[s[right]]);
        while(right-left+1-maxcount>k){
            count[s[left]]--;
            left++;
        }
        maxlen=max(maxlen,right-left+1);
       } 
       return maxlen;
    }
};
