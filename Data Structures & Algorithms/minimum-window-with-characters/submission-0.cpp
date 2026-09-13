class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> windowfreq,targetfreq;
       for(char s:t) targetfreq[s]++;
       int required = targetfreq.size(),start=0,left=0,minlen=INT_MAX,matchcount=0;
       for(int right=0;right<s.size();right++){
        char c = s[right];
        windowfreq[c]++;
        if(targetfreq.count(c) && windowfreq[c]==targetfreq[c]){
            matchcount++;
        }
        while(matchcount==required){
            if(right-left+1<minlen){
                minlen=right-left+1;
                start=left;
            }
            //shrink window
            char lc = s[left];
            windowfreq[lc]--;
            if(targetfreq.count(lc) && windowfreq[lc]<targetfreq[lc]){
                matchcount--;
            }
            left++;
        }
       }
       return minlen==INT_MAX?"":s.substr(start,minlen); 
    }
};
