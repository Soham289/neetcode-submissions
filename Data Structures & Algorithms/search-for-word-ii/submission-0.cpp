class TrieNode {
public:
    TrieNode* children[26] = {};
    string word = "";
};

class Solution {
    vector<string> result;
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // right, down, left, up
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word; // store full word at end node
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char ch = board[i][j];
        if (ch == '#' || node->children[ch - 'a'] == nullptr) return;

        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";  // avoid duplicates
        }

        board[i][j] = '#'; // mark as visited

        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size())
                dfs(board, ni, nj, node);
        }

        board[i][j] = ch; // restore after DFS
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words)
            insertWord(root, word);

        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(board, i, j, root);

        return result;
    }
};
