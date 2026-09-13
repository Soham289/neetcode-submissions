class Solution {
public:
    int greatest(vector<int> &arr,int ind){
        int l=0;
        for(int i=ind+1;i<arr.size();i++){
            if(arr[i]>l) l=arr[i];
        }
        return l;
    }
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            int g = greatest(arr,i);
            arr[i] = g;
        }
        arr[n-1] = -1;
        return arr;
    }
};