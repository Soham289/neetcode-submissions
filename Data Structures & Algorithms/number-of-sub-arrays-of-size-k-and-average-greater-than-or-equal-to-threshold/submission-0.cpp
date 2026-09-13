class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count=0;
        int windowsum=0;
        for(int i=0;i<k;i++){
            windowsum+=arr[i];
        }
        if(windowsum>=k*threshold) count++;
        for(int i=k;i<n;i++){
            windowsum+=arr[i];
            windowsum-=arr[i-k];
            if(windowsum>=threshold*k) count++;
        }
        return count;
    }
};