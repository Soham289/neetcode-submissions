class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxi=0;
       int n = prices.size();
       for(int i=n-1;i>0;i--){
        for(int j=i-1;j>=0;j--){
            int profit=prices[i]-prices[j];
            maxi=max(profit,maxi);
        }
       }
       return maxi; 
    }
};
