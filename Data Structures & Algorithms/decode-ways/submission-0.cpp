class Solution {
public:
    int func(int ind,int n,string s,vector<int> &dp){
        if(ind==n) return 1;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ways = 0;
        ways+=func(ind+1,n,s,dp);
        if (ind + 1 < n) {
            int two = (s[ind] - '0') * 10 + (s[ind + 1] - '0');
            if (two >= 10 && two <= 26)
                ways += func(ind + 2,n, s, dp);
        }
        return dp[ind] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[n] = 1;
        for(int ind=n-1;ind>=0;ind--){
            if(s[ind]=='0') continue;
            int ways=0;
            ways+=dp[ind+1];
            if (ind + 1 < n) {
                int two = (s[ind] - '0') * 10 + (s[ind + 1] - '0');
                if (two >= 10 && two <= 26)
                    ways += dp[ind + 2];
            }
             dp[ind] = ways;
        }
        return dp[0];
    }
};