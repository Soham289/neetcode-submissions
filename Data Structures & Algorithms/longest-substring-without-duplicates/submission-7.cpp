class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0;
        int l=0;
        unordered_map<char,int> mpp;
        for(int r=0;r<s.size();r++){
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l){
                l = mpp[s[r]] + 1;
            }
            mpp[s[r]]=r;
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};
