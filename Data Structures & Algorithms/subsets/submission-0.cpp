class Solution {
public:
    void backtrack(int ind,vector<int> &nums,vector<vector<int>> &result,vector<int> &temp,int n){
        if(ind==n){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        backtrack(ind+1,nums,result,temp,n);
        temp.pop_back();
        backtrack(ind+1,nums,result,temp,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> temp;
        backtrack(0,nums,result,temp,n);
        return result;
    }
};
