// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& nums) {
//         unordered_set<int> st;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 for (int k = j; k < n; k++) {
//                     st.insert(nums[i] ^ nums[j] ^ nums[k]);
//                 }
//             }
//         }

//         return st.size();
//     }
// };


//optimal---
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        int ans = 1;
        while (ans <= n)
            ans <<= 1;

        return ans;
    }
};