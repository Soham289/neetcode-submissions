class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = 0, ele2 = 0, c1 = 0, c2 = 0;
        int n = nums.size();

        // First pass - find candidates
        for (int num : nums) {
            if (num == ele1) c1++;
            else if (num == ele2) c2++;
            else if (c1 == 0) {
                ele1 = num;
                c1 = 1;
            }
            else if (c2 == 0) {
                ele2 = num;
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }

        // Second pass - verify counts
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == ele1) c1++;
            else if (num == ele2) c2++;
        }

        vector<int> result;
        if (c1 > n / 3) result.push_back(ele1);
        if (c2 > n / 3) result.push_back(ele2);
        return result;
    }
};
