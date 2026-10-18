class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int l=0;
        for(int r=0;r<nums.size();r++){
            while(r-l>k){
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.find(nums[r])!=mpp.end()) return true;
            mpp[nums[r]]++;
        }
        return false;
    }
};