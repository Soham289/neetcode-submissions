class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int,int,int>> pq;
        for(auto it:points){
            int distance = ((it[0]*it[0])+(it[1]*it[1]));
            pq.push({distance,it[0],it[1]});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            auto [d, x, y] = pq.top();
            result.push_back({x, y});
            pq.pop();
        }
        return result;

    }
};
