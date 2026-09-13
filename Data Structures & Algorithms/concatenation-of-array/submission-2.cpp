class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // vector<int> arr;
        // int n=0;
        // while(n<2){
        //     for(int i=0;i<nums.size();i++){
        //         arr.push_back(nums[i]);
        //     }
        //     n++;
        // }
        // return arr;
        int n = nums.size();
        vector<int> arr(2*n,0);
        for(int i=0;i<n;i++){
            arr[i]=nums[i];
            arr[i+n]=nums[i];
        }
        return arr;
    }
};