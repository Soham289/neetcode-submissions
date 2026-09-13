class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int maxi=1,cnt=1; 
        map<int,int> mpp;
        for(auto it:nums){
            mpp[it]++;
        } 
        for(auto it:mpp){
            int num = it.first;
            if(mpp.find(num+1)!=mpp.end()){
                cnt++;
            }else{
                maxi=max(cnt,maxi);
                cnt=1;
            }
        }   
        return maxi;
    }
};