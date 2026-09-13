class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int maxtime=0;
       queue<pair<int,pair<int,int>>> q; // {time,{row,col}}
       int m = grid.size();
       int n = grid[0].size();
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({0,{i,j}});
            }
        }
       }
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            int t = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            maxtime=max(maxtime,t);
            for(auto dir:directions){
                int dx = dir.first;
                int dy = dir.second;
                int nx = dx+x;
                int ny = dy+y;
                if(nx<0||nx>=m||ny<0||ny>=n||grid[nx][ny]!=1) continue;
                grid[nx][ny]=2;
                q.push({t+1,{nx,ny}});
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return maxtime;
    }
};
