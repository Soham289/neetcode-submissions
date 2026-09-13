class Solution {
public:
    int func(int ind,int buy,int n,vector<int> &prices,vector<vector<int>> &dp){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int ans1=INT_MIN,ans2=INT_MIN;
        if(buy==1){
            ans1 = max(-prices[ind]+func(ind+1,0,n,prices,dp),func(ind+1,1,n,prices,dp));
        }else{
            ans2 = max(prices[ind]+func(ind+1,1,n,prices,dp),func(ind+1,0,n,prices,dp));
        }
        return dp[ind][buy] = max(ans1,ans2);
    }
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=0;i<=1;i++) dp[n][i]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int ans1=INT_MIN,ans2=INT_MIN;
                if(buy==1){
                    ans1 = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }else{
                    ans2 = max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                }
                dp[ind][buy] = max(ans1,ans2);
            }
        }
       return dp[0][1]; 
    }
};