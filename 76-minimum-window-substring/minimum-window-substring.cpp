class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need;
        for(char c: t) need[c]++;

        int l = 0, cnt = t.size(), minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            if (need[s[r]]-- > 0) cnt--;

            while (cnt == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                if (++need[s[l++]] > 0) cnt++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
