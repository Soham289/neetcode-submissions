class Solution {
public:
    void set(vector<vector<int>> &matrix,int i,int j,int n,int m){
        int a = i;
        while(a>=0){
            matrix[a][j]=0;
            a--;
        }
        a=i;
        while(a<n){
            matrix[a][j]=0;
            a++;
        }
        int b=j;
        while(b>=0){
            matrix[i][b]=0;
            b--;
        }
        b=j;
        while(b<m){
            matrix[i][b]=0;
            b++;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
       vector<pair<int,int>> index;
       for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0) index.push_back({i,j});
        }
       } 
       int n = matrix.size();
       int m = matrix[0].size();
       for(auto& it:index){
            int i = it.first;
            int j = it.second;
            set(matrix,i,j,n,m);
       }
    }
};
