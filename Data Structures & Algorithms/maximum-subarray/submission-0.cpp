class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=-1e9;
        int sum=-1e9;
        for(int num:nums){
            sum=max(num,sum+num);
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
