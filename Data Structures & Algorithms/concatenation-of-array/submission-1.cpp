class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
        int count=2;
        while(count>0){
            count--;
            for(int i=0;i<nums.size();i++){
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};