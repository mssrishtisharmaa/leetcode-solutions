class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int l = 0;
        int r = 0;
        int sum = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0)
                sum += customers[i];
        }

        // first window sum
        while (r < minutes) {
            if (grumpy[r] == 1)
                sum += customers[r];

            r++;
        }
        int ans = sum;
        while (r < grumpy.size()) {
            if (grumpy[r] == 1)
                sum += customers[r];
            // window sum (shrink)
            if (grumpy[l] == 1) {
                sum -= customers[l];
            }
            l++;

            ans = max(ans, sum);

            r++;
        }

        return ans;
    }
};