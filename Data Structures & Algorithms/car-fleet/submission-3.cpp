class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        // Pair each car's position with its time to reach the target
        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort by position descending (closest to target last)
        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double lastTime = 0;

        for (auto& [pos, time] : cars) {
            if (time > lastTime) {
                fleets++;
                lastTime = time;
            }
            // else it joins the previous fleet
        }

        return fleets;
    }
};
