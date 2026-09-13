class Solution {
public:
    vector<int> sizes;
    string encode(vector<string>& strs) {
        string result;
        for(string s:strs){
            int length = s.size();
            sizes.push_back(length);
            result+=s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int j=0;
        for(int i=0;i<sizes.size();i++){
            int length = sizes[i];
            string temp = s.substr(j,length);
            j+=length;
            ans.push_back(temp);
        }
        return ans;
    }
};
