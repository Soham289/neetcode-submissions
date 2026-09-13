class Solution {
public:
    int product(int index,vector<int> &nums){
        int p=1;
        for(int i=0;i<nums.size();i++){
            if(index==i) continue;
            p*=nums[i];
        }
        return p;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int result = product(i,nums);
            ans.push_back(result);
        }
        return ans;
    }
};
