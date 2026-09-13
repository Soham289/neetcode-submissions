class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool found1=false,found2=false,found3=false;
        for(auto it:triplets){
            if(target[0]<it[0]||target[1]<it[1]||target[2]<it[2]) continue;
            if(it[0]==target[0]) found1=true;
            if(it[1]==target[1]) found2=true;
            if(it[2]==target[2]) found3=true;
        }  
        return found1 && found2 && found3;
    }
};