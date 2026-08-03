class Solution {
    inline static string ans[3] = {"Bob", "Tie", "Alice"};

public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();
        vector<int> dp(4, 0); // dp of [0,0,0,0]

        for (int i = n - 1; i >= 0; i--) {

            dp[i % 4] = stoneValue[i] - dp[(i + 1) % 4];

            if (i + 1 < n)
                dp[i % 4] = max(dp[i % 4],
                                stoneValue[i] + stoneValue[i + 1]
                                - dp[(i + 2) % 4]);

            if (i + 2 < n)
                dp[i % 4] = max(dp[i % 4],
                                stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2]
                                - dp[(i + 3) % 4]);
        }

        return ans[(dp[0] > 0) - (dp[0] < 0) + 1];
    }
};