class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxi=0;
       int min_price=INT_MAX;
       for(int price:prices){
        min_price = min(min_price,price);
        maxi=max(maxi,price-min_price);
       }
       return maxi; 
    }
};
