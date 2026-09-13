class Solution {
public:
    bool dfs(int r,int c,int i,string word,vector<vector<char>> &board,int rows,int cols){
            if(i==word.length()) return true;
            if(r<0||c<0||r>=rows||c>=cols||board[r][c]!=word[i]) return false;
            char temp=board[r][c];
            board[r][c]='#';
            bool found = dfs(r+1,c,i+1,word,board,rows,cols)||dfs(r-1,c,i+1,word,board,rows,cols)||dfs(r,c-1,i+1,word,board,rows,cols)||dfs(r,c+1,i+1,word,board,rows,cols);
            board[r][c]=temp;
            return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(board[r][c]==word[0] && dfs(r,c,0,word,board,rows,cols)){
                    return true;
                }
            }
        }
        return false;

    }
};
