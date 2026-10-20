class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,count=0,r;
        int maxi=0;
        vector<int> seen(26,0);
        for(r=0;r<s.size();r++){
            seen[s[r]-'A']++;
            int windowlen = r-l+1;
            int max_count = *max_element(seen.begin(),seen.end());
            while(windowlen-max_count>k){
               seen[s[l]-'A']--;
               l+=1;
               windowlen = r-l+1;
               max_count = *max_element(seen.begin(),seen.end());  
            }
            maxi=max(maxi,r-l+1);
        }  
        return maxi; 
    }
};
