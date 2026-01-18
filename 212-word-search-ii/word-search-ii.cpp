struct Trie {
    Trie* child[26] = {};
    string word = "";
};

class Solution {
public:
    vector<string> res;
    int m, n;

    void dfs(vector<vector<char>>& b, int i, int j, Trie* t) {
        char c = b[i][j];
        if (c == '#' || !t->child[c-'a']) return;
        t = t->child[c-'a'];

        if (!t->word.empty()) {
            res.push_back(t->word);
            t->word = "";
        }

        b[i][j] = '#';
        if (i>0) dfs(b,i-1,j,t);
        if (j>0) dfs(b,i,j-1,t);
        if (i<m-1) dfs(b,i+1,j,t);
        if (j<n-1) dfs(b,i,j+1,t);
        b[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for (auto& w : words) {
            Trie* t = root;
            for (char c : w) {
                if (!t->child[c-'a']) t->child[c-'a'] = new Trie();
                t = t->child[c-'a'];
            }
            t->word = w;
        }

        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dfs(board,i,j,root);

        return res;
    }
};
