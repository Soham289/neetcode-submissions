class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int longest=0;
       if (nums.empty()) return 0;
       unordered_set<int> st(nums.begin(),nums.end());
        for(int num:st){
            if(!st.count(num-1)){
                int currentNum = num;
                int currentStreak = 1;
                while (st.count(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};