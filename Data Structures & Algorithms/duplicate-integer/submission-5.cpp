class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto &x: mpp){
            if(x.second >= 2) return true;
        }
        return false;
    }
};