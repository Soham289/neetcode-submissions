class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto [time, node] = pq.top(); pq.pop();
            for (auto& [nei, wt] : adj[node]) {
                if (dist[node] + wt < dist[nei]) {
                    dist[nei] = dist[node] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
