class LRUCache {
private:
    int capacity;
    list<pair<int, int>> lruList; 
    unordered_map<int, list<pair<int, int>>::iterator> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        lruList.splice(lruList.begin(), lruList, cache[key]);
        return cache[key]->second;
    }
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->second = value;
            lruList.splice(lruList.begin(), lruList, cache[key]);
        } else {
            if (lruList.size() == capacity) {
                int lruKey = lruList.back().first;
                lruList.pop_back();
                cache.erase(lruKey);
            }
            lruList.push_front({key, value});
            cache[key] = lruList.begin();
        }
    }
};