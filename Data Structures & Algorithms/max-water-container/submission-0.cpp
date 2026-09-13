class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int n = height.size();
        int l=0,r=n-1;
        while(l<=r){
            int current = (r-l)*min(height[l],height[r]);
            maxi=max(maxi,current);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxi;
    }
};