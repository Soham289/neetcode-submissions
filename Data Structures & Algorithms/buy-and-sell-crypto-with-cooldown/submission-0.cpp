class Solution {
public:
    int func(int ind,int buy,int n,vector<int> &prices,vector<vector<int>> &dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int ans1=0,ans2=0;
        if(buy==1){
            ans1 = max(-prices[ind]+func(ind+1,0,n,prices,dp),func(ind+1,1,n,prices,dp));
        }else{
            ans2 = max(prices[ind]+func(ind+2,1,n,prices,dp),func(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy]=max(ans1,ans2);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy=1;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return func(0,1,n,prices,dp);
    }
};
