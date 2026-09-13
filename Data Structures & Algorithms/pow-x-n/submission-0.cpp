class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0.0;
        if(n<0){ 
            x=1/x;
            n=-n;
        }
       double result=1;
       for(int i=0;i<n;i++){
            result*=x;
       } 
       return result;
    }
};
