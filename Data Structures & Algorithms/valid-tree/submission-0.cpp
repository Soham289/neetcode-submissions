class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int node = q.front();q.pop();
            for(int neighbor: adj[node]){
                if(visited[neighbor]) continue;
                visited[neighbor] = true;
                //remove back edge
                adj[neighbor].erase(remove(adj[neighbor].begin(),adj[neighbor].end(),node),adj[neighbor].end());
                q.push(neighbor);
            }
        }
        for(bool v:visited){
            if(!v) return false;
        }
        return true;
    }
};
