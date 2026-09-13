class Solution {
public:
    int reverse(int x) {
        string temp = to_string(x);
        std::reverse(temp.begin(), temp.end());
        if (temp.back() == '-') {
            temp.pop_back(); 
            try {
                int ans = stoi(temp);
                return -ans;
            } catch (...) {
                return 0; 
            }
        } else {
            try {
                return stoi(temp);
            } catch (...) {
                return 0; 
            }
        }
    }
};
