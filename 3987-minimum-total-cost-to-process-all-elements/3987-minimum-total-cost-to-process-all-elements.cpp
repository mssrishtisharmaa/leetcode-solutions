class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        vector<int> sovalemrin = nums;

        const long long MOD = 1e9 + 7;
        const long long INV2 = 500000004;

        long long available_resource = k;
        long long tcount = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (available_resource < nums[i]) {

                long long need = nums[i] - available_resource;

                // Number of operations needed = ceil(need / k)
                long long count = (need + k - 1) / k;

                tcount += count;
                available_resource += count * 1LL * k;
            }

            available_resource -= nums[i];
        }

        long long ans = ((tcount % MOD) * ((tcount + 1) % MOD)) % MOD;
        ans = (ans * INV2) % MOD;

        return ans;
    }
};

// avalable resouce traverse 
//if reacouse < then need - need _count ++ count ++ - toatl resouce = avalble + need_count * k 