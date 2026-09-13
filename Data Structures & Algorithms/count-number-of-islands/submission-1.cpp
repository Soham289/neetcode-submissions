class Solution {
public:
    void dfs(int row,int col,int delrow[],int delcol[],vector<vector<char>> &grid,int n,int m,vector<vector<int>> &vis){
        if(vis[row][col]==1 || grid[row][col]=='0') return;
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,delrow,delcol,grid,n,m,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,1,-1};
        int cc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cc++;
                    dfs(i,j,delrow,delcol,grid,n,m,vis);
                }
            }
        }
        return cc;
    }
};
