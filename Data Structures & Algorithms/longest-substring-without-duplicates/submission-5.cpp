class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.size()==0) return 0;
      int maxi=1;
      unordered_map<char,int> mpp;
      int l=0,r=0;
      while(l<s.size() && r<s.size() && l<=r){
        char c = s[r];
        if(mpp.find(c)!=mpp.end()){
            int index = mpp[c];
            l=max(index+1,l);
        }
        mpp[c]=r;
        maxi=max(maxi,r-l+1);
        r++;
      }
      return maxi;   
    }
};
