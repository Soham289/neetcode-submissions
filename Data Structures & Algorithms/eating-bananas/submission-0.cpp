class Solution {
public:
    bool valid(vector<int> &piles,int h,int k){
        int hour = 0;
        for (int pile : piles) {
            hour += (pile + k - 1) / k;  
        }
        return hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid = (high+low)/2;
            if(valid(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
