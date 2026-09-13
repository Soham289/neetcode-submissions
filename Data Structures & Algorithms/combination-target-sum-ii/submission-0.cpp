class Solution {
public:
    void backtrack(int start, int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result){
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            if (nums[i] > target) break; 
            temp.push_back(nums[i]);
            backtrack(i + 1, target - nums[i], nums, temp, result);  
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(0, target, candidates, temp, result);
        return result;
    }
};
