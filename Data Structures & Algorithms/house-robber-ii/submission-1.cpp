class Solution {
public:
    int func(int ind,int n,vector<int> &nums,vector<int> &dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take = nums[ind]+func(ind+2,n,nums,dp);
        int not_take = func(ind+1,n,nums,dp);
        return dp[ind]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        vector<int> dp2(n+1,-1);
        int first = func(0,n-1,nums,dp);
        int second = func(1,n,nums,dp2);
        return max(first,second);
    }
};
