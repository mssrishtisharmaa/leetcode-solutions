class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums , k-1);
        
    }
private:
int atmost(vector<int> nums, int k){
    int l = 0; int r = 0;
    int sum = 0;
    int cnt = 0;
    while (r < nums.size()){
        sum += nums[r] % 2;

        while ( sum > k){
            sum -= nums[l] %2;

            l++;
        }
        cnt += (r-l+1);

        r++;
    }
    return cnt;
} 
};