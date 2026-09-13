class CountSquares {
public:
    map<pair<int, int>, int> mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int a = point[0];
        int b = point[1];
        for(auto p : mp){
            auto [x, y] = p.first;
            if(abs(x-a) == abs(y-b) && (a != x && b != y)){
                int c1 = mp[{x,y}];
                int c2 = mp[{a,y}];
                int c3 = mp[{x,b}];

                count += c1*c2*c3;
            }
        }
        return count;
    }
};
