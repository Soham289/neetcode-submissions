class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j, int n, int m, int prevHeight) {
        if (i < 0 || j < 0 || i >= n || j >= m || ocean[i][j] || heights[i][j] < prevHeight)
            return;

        ocean[i][j] = 1;

        dfs(heights, ocean, i + 1, j, n, m, heights[i][j]);
        dfs(heights, ocean, i - 1, j, n, m, heights[i][j]);
        dfs(heights, ocean, i, j + 1, n, m, heights[i][j]);
        dfs(heights, ocean, i, j - 1, n, m, heights[i][j]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> result;

        // Pacific (top row + left column)
        for (int i = 0; i < n; i++) dfs(heights, pacific, i, 0, n, m, heights[i][0]);
        for (int j = 0; j < m; j++) dfs(heights, pacific, 0, j, n, m, heights[0][j]);

        // Atlantic (bottom row + right column)
        for (int i = 0; i < n; i++) dfs(heights, atlantic, i, m - 1, n, m, heights[i][m - 1]);
        for (int j = 0; j < m; j++) dfs(heights, atlantic, n - 1, j, n, m, heights[n - 1][j]);

        // Intersection
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
