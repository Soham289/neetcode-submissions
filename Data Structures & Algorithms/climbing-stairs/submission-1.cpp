class Solution {
public:
    int func(int n,vector<int> &dp){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=func(n-1,dp)+func(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        for(int i=0;i<=2;i++) dp[i]=i;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
