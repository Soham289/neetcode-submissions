class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int it:nums){
            st.insert(it);
        }
        int s = st.size();
        nums = vector<int>(st.begin(),st.end());
        return s;
    }
};