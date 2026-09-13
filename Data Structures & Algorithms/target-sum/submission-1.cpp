class Solution {
public:
    int func(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(ind==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || nums[0]==target) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take = func(ind-1,target,nums,dp);
        int take = 0;
        if(nums[ind]<=target){
            take = func(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=not_take+take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if ((totalSum + target) % 2 != 0 || target > totalSum) return 0;
        int sum = (totalSum + target) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return func(n-1,sum,nums,dp);
    }
};
