class Solution {
public:
    bool func(int ind,int target,vector<int> &nums,vector<vector<int>> &dp){
        if(target==0) return true;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int n = nums.size();
        if(ind==n-1) return nums[ind]==target;
        bool not_take = func(ind+1,target,nums,dp);
        bool take = false;
        if(nums[ind]<=target){
            take = func(ind+1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]=take||not_take;
    }
    bool canPartition(vector<int>& nums) {
        int totsum=0;
        for(int num:nums) totsum+=num;
        if(totsum%2!=0) return false;
        int k = totsum/2;
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return func(0,k,nums,dp);
    }
};