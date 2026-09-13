class Solution {
public:
    int func(int ind,int n,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(ind==n-1){
            if(amount>0 && amount%coins[ind]==0) return amount/coins[ind];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int not_take = func(ind+1,n,amount,coins,dp);
        int take = 1e9;
        if(coins[ind]<=amount){
            take = 1+func(ind,n,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=min(not_take,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = func(0,n,amount,coins,dp);
        return ans>=1e9? -1:ans;
    }
};
