class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {      
    }
    void set(string key, string value, int timestamp) {
     mp[key].push_back({timestamp,value});   
    }
    
    string get(string key, int timestamp) {
        if (!mp.count(key)) return "";
        const auto& vec = mp[key];
        int low = 0, high = vec.size() - 1;
        string res = "";
        while (low <= high) {
            int mid = (low + high) / 2;
            if (vec[mid].first == timestamp)
                return vec[mid].second;
            else if (vec[mid].first < timestamp) {
                res = vec[mid].second;  
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};
