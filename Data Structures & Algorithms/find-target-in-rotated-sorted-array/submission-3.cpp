class Solution {
public:
    int binarySearch(vector<int> &nums,int left,int right,int target){
        if(left>right)
            return -1;
        int mid = (left+right)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target){
            return binarySearch(nums, mid+1, right, target);
        }
        else{
            return binarySearch(nums, left, mid-1, target);
        }
    }
    int search(vector<int>& nums, int target) {
       int low=0,high=nums.size()-1;
       int ans1=-1,ans2=-1,ans3=-1;
       while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<=nums[high]){
                if(target>=nums[mid] && target<=nums[high]){
                    ans1 = binarySearch(nums,mid,high,target);
                    return ans1;
                }else{
                    high=mid-1;
                }
            }else if(nums[mid]>=nums[low]){
                if(target>=nums[low] && target<=nums[mid]){
                    ans2=binarySearch(nums,low,mid,target);
                    return ans2;
                }else{
                    low=mid+1;
                }
            }
        }
        return max(ans1,ans2); 
    }
};