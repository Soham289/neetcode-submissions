class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = strs.size();
        if(strs.size()==0) return ans;
        vector<string> temp1 = strs;
        for(int i=0;i<temp1.size();i++){
            sort(temp1[i].begin(),temp1[i].end());
        }
        vector<int> vis(n,0);
        for(int i=0;i<strs.size();i++){
            vector<string> temp;
            if(vis[i]==1) continue;
            temp.push_back(strs[i]);
            vis[i]=1;
            for(int j=i;j<n;j++){
                if(i!=j && temp1[i]==temp1[j]){
                    vis[j]=1;
                    temp.push_back(strs[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
