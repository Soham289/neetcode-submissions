// DFS for Eulerian Path
class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adj;
    vector<string> result;
    void dfs(string airport){
        auto& dests = adj[airport];
        while(!dests.empty()){
            string next = dests.top();
            dests.pop();
            dfs(next);
        }
        result.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket:tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
