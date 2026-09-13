class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int count = 1;
        int prevEnd = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                count++;
                prevEnd = intervals[i][1]; 
            }
        }
        return intervals.size() - count;
    }
};
