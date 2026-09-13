class Solution {
public:
    bool rowcheck(char c,int row,int col,vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(row==i||board[i][col]=='.') continue;
            if(c==board[i][col]) return false;
        }
        return true;
    }
    bool colcheck(char c,int row,int col,vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            if(col==i||board[row][i]=='.') continue;
            if(c==board[row][i]) return false;
        }
        return true;
    }
    bool gridcheck(int row, int col, vector<vector<char>> &board) {
        unordered_set<char> seen;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (seen.count(c)) return false;
                seen.insert(c);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                char c = board[i][j];
                bool flag1=rowcheck(c,i,j,board);
                bool flag2=colcheck(c,i,j,board);
                if(flag1==false||flag2==false) return false;
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!gridcheck(i, j, board)) return false;
            }
        }
        return true;
    }
};
