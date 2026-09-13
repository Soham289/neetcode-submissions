class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        using pii = pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        vector<int> minDist(n,INT_MAX);
        vector<int> vis(n,0);
        pq.push({0,0});
        int total=0,visitedcnt=0;
        while(visitedcnt<n){
            int cost = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(vis[u]==1) continue;
            vis[u]=1;
            visitedcnt++;
            total+=cost;
            for(int v=0;v<n;v++){
                if(!vis[v]){
                    int d = abs(points[u][0] - points[v][0]) +abs(points[u][1] - points[v][1]);
                    pq.push({d,v});
                }
            }
        }
        return total;
    }
};
