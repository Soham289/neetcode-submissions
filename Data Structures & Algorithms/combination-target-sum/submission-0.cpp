class Solution {
public:
    void backtrack(int ind,int n,int target,vector<int> &nums,vector<vector<int>> &result,vector<int> &temp){
        if(ind==n || target<0) return;
        if(target==0){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        backtrack(ind,n,target-nums[ind],nums,result,temp);
        temp.pop_back();
        backtrack(ind+1,n,target,nums,result,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        int n = nums.size();
        backtrack(0,n,target,nums,result,temp);
        return result;
    }
};
