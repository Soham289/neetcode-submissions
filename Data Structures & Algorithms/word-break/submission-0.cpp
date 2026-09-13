class Solution {
public:
    bool canBreak(int start,string s,unordered_set<string> &dict,vector<int> &dp){
        if(start==s.size()) return true;
        if(dp[start]!=-1) return dp[start];
        for(int end = start+1;end<=s.size();end++){
            string word = s.substr(start,end-start);
            if(dict.count(word) && canBreak(end,s,dict,dp)){
                return dp[start]=true;
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1); 
        return canBreak(0,s,dict,dp);
    }
};