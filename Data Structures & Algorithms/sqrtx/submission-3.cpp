class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;  
       int low=1,high=x/2;
       while(low<=high){
        long long mid = (low+high)/2;
        long long result = mid*mid;
        if(result==(long long)x) return mid;
        else if(result>x) high=mid-1;
        else low = mid+1;
       } 
       return high;
    }
};