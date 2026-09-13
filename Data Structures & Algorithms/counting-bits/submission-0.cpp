class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++){
            int ans = hammingWeight(i);
            result.push_back(ans);
        }
        return result;
    }
};
