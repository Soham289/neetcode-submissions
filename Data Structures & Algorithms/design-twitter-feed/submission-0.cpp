class Twitter {
public:
    int time = 0;

    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        // Ensure self-follow
        follows[userId].insert(userId);

        for (int followee : follows[userId]) {
            for (auto& t : tweets[followee]) {
                maxHeap.push(t);
            }
        }

        vector<int> res;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            count++;
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};
