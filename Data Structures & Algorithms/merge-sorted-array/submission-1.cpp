class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int t = (m+n)-1;
        int i=0;
        while(t>=m && i<n){
            nums1[t--]=nums2[i++];
        }
        sort(nums1.begin(),nums1.end());
        return;
    }
};