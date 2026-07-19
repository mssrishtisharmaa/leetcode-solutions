class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);

        // Store last occurrence of each character
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        vector<bool> visited(26, false);
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Skip if already included
            if (visited[c - 'a'])
                continue;

            // Remove larger characters that appear later
            while (!st.empty() &&
                   c < st.top() &&
                   last[st.top() - 'a'] > i) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
        }

        // Convert stack to string
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};