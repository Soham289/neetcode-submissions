class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
       if(grid.empty()) return ;
       int m = grid.size();
       int n = grid[0].size();
       queue<pair<int,int>> q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0) q.push({i,j});
        }
       } 
       vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
       while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(auto [dx,dy]:directions){
                int nx = x+dx;
                int ny = y+dy;
                if(nx<0||nx>=m||ny<0||ny>=n||grid[nx][ny]!=INT_MAX) continue;
                grid[nx][ny] = 1+grid[x][y];
                q.push({nx,ny});
            }
       }
    }
};
