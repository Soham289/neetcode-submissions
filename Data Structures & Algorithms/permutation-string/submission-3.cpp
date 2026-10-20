class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0;i<s1.size();i++){
            v1[s1[i]-'a']++;
        }
        int s = s1.size();
        int l=0;
        for(int r=0;r<s2.size();r++){
            while(r-l+1>s){
                v2[s2[l]-'a']--;
                l+=1;
            }
            v2[s2[r]-'a']++;
            if(r-l+1==s){
                 if(v1==v2) return true;
            }
        }
        return false;
    }
};
