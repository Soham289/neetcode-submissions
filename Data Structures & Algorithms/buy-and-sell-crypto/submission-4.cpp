class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX,maxi=INT_MIN;
        for(auto it:prices){
            mini = min(mini,it);
            maxi = max(maxi,it-mini);
        }
        return maxi;
    }
};
