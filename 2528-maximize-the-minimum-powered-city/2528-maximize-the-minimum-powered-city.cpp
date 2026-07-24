class Solution {
public:
    bool check(vector<int>& stations, int r, int k, long long target) {
        int n = stations.size();

        vector<long long> power(n);
        long long window = 0;

        // Initial power using sliding window
        for (int i = 0; i <= min(n - 1, r); i++)
            window += stations[i];

        power[0] = window;

        for (int i = 1; i < n; i++) {
            if (i + r < n)
                window += stations[i + r];

            if (i - r - 1 >= 0)
                window -= stations[i - r - 1];

            power[i] = window;
        }

        vector<long long> diff(n + 1, 0);

        long long add = 0;
        long long used = 0;

        for (int i = 0; i < n; i++) {

            add += diff[i];

            if (power[i] + add < target) {

                long long need = target - power[i] - add;

                used += need;

                if (used > k)
                    return false;

                add += need;

                int end = min(n, i + 2 * r + 1);

                if (end < n)
                    diff[end] -= need;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {

        long long low = 0;
        long long high = 0;

        for (int x : stations)
            high += x;

        high += k;

        while (low < high) {

            long long mid = (low + high + 1) / 2;

            if (check(stations, r, k, mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};