class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && a < 0) {  // possible collision
                if (abs(st.top()) < abs(a)) {
                    st.pop();       // top asteroid destroyed
                    continue;       // keep checking with next
                } else if (abs(st.top()) == abs(a)) {
                    st.pop();       // both destroyed
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;  // new asteroid destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(a);
            }
        }

        // build result
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
