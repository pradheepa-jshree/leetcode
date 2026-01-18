class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string w = q.front(); q.pop();
                if (w == endWord) return steps;

                for (int i = 0; i < w.size(); i++) {
                    char old = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        w[i] = c;
                        if (dict.count(w)) {
                            q.push(w);
                            dict.erase(w);
                        }
                    }
                    w[i] = old;
                }
            }
            steps++;
        }
        return 0;
    }
};
