class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //using prefix sun + hashmap

        map<int  ,int > mpp;
        mpp[0] = 1;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size() ;i ++){
            sum += nums[i] %2;
            int rem = sum - k;
            cnt += mpp[rem];
            mpp[sum] ++;
        }
        return cnt;
        
    }

};



// using sliding window 
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         return atmost(nums, k) - atmost(nums , k-1);
        
//     }
// private:
// int atmost(vector<int> nums, int k){
//     int l = 0; int r = 0;
//     int sum = 0;
//     int cnt = 0;
//     while (r < nums.size()){
//         sum += nums[r] % 2;

//         while ( sum > k){
//             sum -= nums[l] %2;

//             l++;
//         }
//         cnt += (r-l+1);

//         r++;
//     }
//     return cnt;
// } 
// };