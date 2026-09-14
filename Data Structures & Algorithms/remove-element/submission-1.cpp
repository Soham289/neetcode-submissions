class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0,r=nums.size()-1;
         while(l <= r) {
            if(nums[l] == val) {
                while(l <= r && nums[r] == val) {
                    r--;
                }
                if(l <= r) {
                    swap(nums[l], nums[r]);
                    r--;
                }
            }
            l++;
        }
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val) k++;
        }
        return k;
    }
};