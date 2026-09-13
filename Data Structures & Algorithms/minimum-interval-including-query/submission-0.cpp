class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> query_with_index;
        for (int i = 0; i < queries.size(); ++i) {
            query_with_index.push_back({queries[i], i});
        }
        sort(query_with_index.begin(), query_with_index.end());
        vector<int> result(queries.size(), -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int i = 0;
        for (auto &[q, idx] : query_with_index) {
            // Push intervals that start before or at query
            while (i < intervals.size() && intervals[i][0] <= q) {
                int l = intervals[i][0], r = intervals[i][1];
                pq.push({r - l + 1, r});
                i++;
            }
            // Remove intervals that end before query
            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }
            if (!pq.empty()) {
                result[idx] = pq.top().first;
            }
        }
        return result;
    }
};
