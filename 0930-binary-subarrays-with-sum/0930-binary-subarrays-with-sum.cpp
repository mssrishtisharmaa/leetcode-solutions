class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
       map<int , int> mpp;
       mpp[0] = 1;
       int prefix_sum = 0;
       int cnt = 0;
       for(int i = 0; i < nums.size() ; i++){
        prefix_sum += nums[i];
        int remove = prefix_sum - goal;
        cnt += mpp[remove];
        mpp[prefix_sum] += 1;
       }
       return cnt;
    }
};


