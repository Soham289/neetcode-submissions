class Solution {
private:
    int findlar(unordered_map<int,int> &mpp){
        int maxfreq = -1;
        int element = -1;
        for (auto& it : mpp) {
            if (it.second > maxfreq) {
                maxfreq = it.second;
                element = it.first;
            }
        }
        mpp.erase(element);  
        return element;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<k;i++){
            int maxi = findlar(mpp);
            result.push_back(maxi);
        }
        return result;
    }
};
