class  DisjointSet{
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    bool unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return false;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        return true;
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size();
       DisjointSet ds(n*n);
       vector<tuple<int,int,int>> cells; // height,i,j
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cells.push_back({grid[i][j],i,j});
        }
       } 
       sort(cells.begin(),cells.end());
       vector<vector<bool>> vis(n,vector<bool>(n,false));
       vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
       for(auto cell:cells){
            int height = get<0>(cell);
            int i = get<1>(cell);
            int j = get<2>(cell);
            vis[i][j] = true;
            int currId = i*n+j;
            for(auto dir:dirs){
                int dx = dir.first;
                int dy = dir.second;
                int ni = i+dx;
                int nj = j+dy;
                if(ni>=0 && ni<n && nj>=0 && nj<n && vis[ni][nj]){
                    int adjnode = ni*n+nj;
                    ds.unionBySize(currId,adjnode);
                }
            }
            if(ds.findUPar(0)==ds.findUPar(n*n-1)) return height;
       }
       return -1;
    }
};
