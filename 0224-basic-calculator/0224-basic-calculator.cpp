class Solution {
public:
    int calculate(string s) {

        stack<int> st;

        int ans = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            if (isdigit(c)) {

                long num = 0;

                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                ans += sign * num;
                i--;
            }

            else if (c == '+')
                sign = 1;

            else if (c == '-')
                sign = -1;

            else if (c == '(') {

                st.push(ans);
                st.push(sign);

                ans = 0;
                sign = 1;
            }

            else if (c == ')') {

                int prevSign = st.top();
                st.pop();

                int prevAns = st.top();
                st.pop();

                ans = prevAns + prevSign * ans;
            }
        }

        return ans;
    }
};