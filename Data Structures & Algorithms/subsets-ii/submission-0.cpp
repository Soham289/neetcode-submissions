class Solution {
public:
    void backtrack(int ind,int n,vector<int> &temp,vector<int> &nums,vector<vector<int>> &result){
        result.push_back(temp);
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i-1]==nums[i]) continue;
            temp.push_back(nums[i]);
            backtrack(i+1,n,temp,nums,result);
            temp.pop_back();
        }
 
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        backtrack(0,n,temp,nums,result);
        return result;
    }
};
