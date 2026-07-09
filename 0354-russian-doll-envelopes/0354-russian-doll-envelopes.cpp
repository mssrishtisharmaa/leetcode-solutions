class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //Step 1: Sort by width ascending.
        // If widths are equal, sort height in descending order.
        sort(envelopes.begin(), envelopes.end(),
            [](vector<int>& a, vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];
                return a[0] < b[0];
            });

        // Step 2: Find LIS on heights
        vector<int> lis;

        for (auto &env : envelopes) {

            int h = env[1];

            // Find the first element >= h
            auto it = lower_bound(lis.begin(), lis.end(), h);

            if (it == lis.end()) {
                // Extend the LIS
                lis.push_back(h);
            } else {
                // Replace to keep future options open
                *it = h;
            }
        }

        return lis.size();
        
    }
};