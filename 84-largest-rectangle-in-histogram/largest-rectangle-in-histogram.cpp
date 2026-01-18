class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        h.push_back(0);
        int ans = 0;

        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }
};
