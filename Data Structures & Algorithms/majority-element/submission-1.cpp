class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int maj=nums[0],c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==maj){
                c++;
            }else{
                c--;
                if(c<0){
                    maj=nums[i];
                    c=1;
                }
            }
        }
        return maj;
    }
};