class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int l=0;
        int s=INT_MAX;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                s=min(s,r-l+1); 
                sum-=nums[l];
                l+=1;
            }  
        }
        if(s==INT_MAX) return 0;
        return s;
    }
};