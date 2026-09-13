class Solution {
public:
    int func(int ind,int n,vector<int> &cost,vector<int> &dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int first = cost[ind]+func(ind+1,n,cost,dp);
        int second = cost[ind]+func(ind+2,n,cost,dp);
        return dp[ind]=min(first,second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int first = func(0,n,cost,dp1);
        int second = func(1,n,cost,dp2);
        return min(first,second);
    }
};
