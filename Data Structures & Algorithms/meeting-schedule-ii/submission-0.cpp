class Solution {
public:
    static bool comp(const Interval &a, const Interval &b) {
        return a.start < b.start;
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0].end);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= pq.top()) {
                pq.pop();  // Reuse room
            }
            pq.push(intervals[i].end);  // Allocate room
        }
        return pq.size();  // Number of rooms needed
    }
};
