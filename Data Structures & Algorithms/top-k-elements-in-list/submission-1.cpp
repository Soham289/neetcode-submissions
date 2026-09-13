class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto it:mpp){
            int num = it.first;
            int count=it.second;
            pq.push({count,num});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            int it = pq.top().second;
            result.push_back(it);
            pq.pop();
        }
        return result;
    }
};
