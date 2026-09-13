class Solution {
public:
    void rotate1(vector<int> &nums){
        int n = nums.size();
        int temp = nums[n-1];
        for(int i=nums.size()-1;i>0;i--){
            nums[i] = nums[i-1]; 
        }
        nums[0] = temp;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        for(int i=0;i<k;i++){
            rotate1(nums);
        }
    }
};