class Solution {
public:
    void expandFromCenter(const string &s, int left, int right, int &count)
    {
        while (left >= 0 && right < s.size() && (s[left] == s[right]))
        {
            ++count;
            ++right;
            --left;
        }
    }
    int countSubstrings(string s) {
        if(s.empty())
            return 0;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            expandFromCenter(s, i, i, count);
            expandFromCenter(s, i, i + 1, count);
        }
        return count;
    }
};
