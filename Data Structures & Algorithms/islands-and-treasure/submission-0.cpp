class Solution {
public:
     void islandsAndTreasure(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n == 0) return;
        int m = rooms[0].size();
        queue<pair<int, int>> q;
        // Push all treasure into the queue
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                // If it's a valid empty room
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    rooms[nrow][ncol] == INT_MAX) {
                    rooms[nrow][ncol] = rooms[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};
