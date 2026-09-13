class Solution {
public:
    int func(int ind,int n,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(amount==0) return 1;
        if(ind==n-1){
            if(amount%coins[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take = func(ind+1,n,amount,coins,dp);
        int take = 0;
        if(coins[ind]<=amount){
            take = func(ind,n,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=not_take+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return func(0,n,amount,coins,dp);
    }
};
