class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int m, int n) {
        if(dp[i][j] != -1) return dp[i][j];
        int maxLen = 1;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for(auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(ni, nj, matrix, dp, m, n));
            }
        }
        return dp[i][j] = maxLen;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       if(matrix.empty()||matrix[0].empty()) return 0;
       int m = matrix.size();
       int n = matrix[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
       int ans = 0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans = max(ans,dfs(i,j,matrix,dp,m,n));
        }
       } 
       return ans;
    }
};
